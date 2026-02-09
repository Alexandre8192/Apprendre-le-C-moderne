#!/usr/bin/env python3
"""Validate local Markdown links in the repository."""

from __future__ import annotations

import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LINK_RE = re.compile(r"\[[^\]]+\]\(([^)]+)\)")
FENCE_RE = re.compile(r"```[\s\S]*?```", re.MULTILINE)


def iter_markdown_files(root: Path) -> list[Path]:
    files: list[Path] = []
    for path in root.rglob("*.md"):
        if ".git" in path.parts:
            continue
        files.append(path)
    return sorted(files)


def validate_links(path: Path) -> list[str]:
    text = path.read_text(encoding="utf-8")
    text = FENCE_RE.sub("", text)

    errors: list[str] = []
    for match in LINK_RE.finditer(text):
        raw_target = match.group(1).strip()
        if not raw_target:
            continue
        if raw_target.startswith(("http://", "https://", "mailto:", "#")):
            continue
        if raw_target.startswith("<") and raw_target.endswith(">"):
            raw_target = raw_target[1:-1]

        target = raw_target.split("#", 1)[0].strip()
        if not target:
            continue

        resolved = (path.parent / target).resolve()
        if not resolved.exists():
            rel_file = path.relative_to(ROOT).as_posix()
            rel_target = (path.parent / target).relative_to(ROOT).as_posix()
            errors.append(f"{rel_file}: link '{raw_target}' -> missing '{rel_target}'")
    return errors


def main() -> int:
    all_errors: list[str] = []
    for md in iter_markdown_files(ROOT):
        all_errors.extend(validate_links(md))

    if all_errors:
        print("Broken Markdown links detected:")
        for err in all_errors:
            print(f"- {err}")
        return 1

    print("OK: no broken local Markdown links found.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
