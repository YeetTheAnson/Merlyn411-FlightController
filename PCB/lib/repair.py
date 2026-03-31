#!/usr/bin/env python3
"""
Repair extra top-level closing parentheses in KiCad .kicad_sym files.

The script assumes there is a single main form starting with
'(kicad_symbol_lib'. It removes any early closing parenthesis that would
close this form before the end of the file.
"""

import argparse
from pathlib import Path


def fix_kicad_sym_parens(text: str) -> str:
    root_keyword = "(kicad_symbol_lib"
    root_idx = text.find(root_keyword)
    if root_idx == -1:
        return text

    main_open_idx = root_idx

    try:
        last_non_ws_idx = max(
            i for i, ch in enumerate(text) if not ch.isspace()
        )
    except ValueError:
        return text

    out_chars = []
    depth = 0
    in_string = False
    escape = False
    root_started = False

    for i, ch in enumerate(text):
        if i == main_open_idx:
            root_started = True

        if ch == '"' and not escape:
            in_string = not in_string
            out_chars.append(ch)
            escape = False
            continue

        if ch == '\\' and not escape:
            out_chars.append(ch)
            escape = True
            continue

        if escape:
            out_chars.append(ch)
            escape = False
            continue

        if not in_string and root_started and ch in "()":
            if ch == '(':
                depth += 1
                out_chars.append(ch)
            else:  # ')'
                if depth > 1:
                    depth -= 1
                    out_chars.append(ch)
                elif depth == 1:
                    if i == last_non_ws_idx:
                        depth -= 1
                        out_chars.append(ch)
                    else:
                        # Early top-level close: drop it
                        pass
                else:
                    # Unmatched ')' at depth 0 inside root: drop it
                    pass
        else:
            out_chars.append(ch)

    fixed_text = "".join(out_chars)

    if depth > 0:
        fixed_text += ")" * depth

    return fixed_text


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Fix extra top-level ')' in KiCad .kicad_sym libraries."
    )
    parser.add_argument(
        "file",
        type=Path,
        help="Path to the .kicad_sym file to repair.",
    )
    parser.add_argument(
        "-i",
        "--in-place",
        action="store_true",
        help="Modify the file in place (create a .bak backup).",
    )

    args = parser.parse_args()
    path: Path = args.file

    original = path.read_text(encoding="utf-8")
    fixed = fix_kicad_sym_parens(original)

    if fixed == original:
        print("No changes made: file already looks consistent.")
        return

    if args.in_place:
        backup = path.with_suffix(path.suffix + ".bak")
        backup.write_text(original, encoding="utf-8")
        path.write_text(fixed, encoding="utf-8")
        print(f"Repaired file written in place.\nBackup: {backup}")
    else:
        out_path = path.with_suffix(path.suffix + ".fixed")
        out_path.write_text(fixed, encoding="utf-8")
        print(f"Repaired file written to: {out_path}")


if __name__ == "__main__":
    main()