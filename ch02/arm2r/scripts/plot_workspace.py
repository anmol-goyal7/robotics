#!/usr/bin/env python3
"""Plot the 2R workspace from CSV on stdin.

Usage: ./build/sample_workspace | python3 scripts/plot_workspace.py
"""
import csv
import sys
from pathlib import Path

import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.patches import Circle

OUT = Path(__file__).resolve().parent.parent / "docs" / "workspace.png"


def main():
    reader = csv.DictReader(sys.stdin)
    xs, ys = [], []
    for row in reader:
        xs.append(float(row["x"]))
        ys.append(float(row["y"]))

    fig, ax = plt.subplots(figsize=(6, 6))
    ax.scatter(xs, ys, s=1)
    for r in (1.0, 3.0):
        ax.add_patch(Circle((0, 0), r, fill=False, linestyle="--", color="k"))
    ax.set_aspect("equal")
    ax.set_xlim(-3.3, 3.3)
    ax.set_ylim(-3.3, 3.3)
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_title("2R workspace (L1=2, L2=1)")

    OUT.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUT, dpi=150, bbox_inches="tight")


if __name__ == "__main__":
    main()
