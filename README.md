# DSA-CP Projects

A comprehensive collection of Data Structures & Algorithms practice problems and solutions implemented in C++. Organized by topic to facilitate learning, reference, and competitive programming.

## Table of Contents

- [Overview](#overview)
- [Getting Started](#getting-started)
- [Directory Structure](#directory-structure)
- [Root Problem Solutions](#root-problem-solutions)
- [Sample Input/Output](#sample-inputoutput)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

This repository contains solutions to a wide range of competitive programming problems and classic data structure & algorithm challenges. Each directory groups related problems and demonstrates common techniques, time complexities, and potential pitfalls.

## Getting Started

### Prerequisites

- C++17 compatible compiler (e.g., `g++`, `clang++`)
- Make or build tool (optional)
- Visual Studio Code or any IDE of your choice

## Directory Structure

The project is organized into topic-focused modules:

| Directory                                          | Description                                                         | Key Concepts                             | Sample Problems                        |
|----------------------------------------------------|---------------------------------------------------------------------|------------------------------------------|----------------------------------------|
| advanced-combinatorics/                            | Hard combinatorial & optimization puzzles                           | Combinatorics, DFS, heuristic pruning    | 4-sum, advanced DP                     |
| search-techniques/                                 | Classic and parametric binary search techniques                     | O(log n), boundary conditions            | First/last occurrence search           |
| union-find/                                        | Dynamic connectivity using Union-Find                                | Union by rank, path compression          | Connected components                   |
| dynamic-programming/                               | Top-down and bottom-up dynamic programming                          | Memoization, state transition           | Knapsack, LIS                          |
| fenwick-tree/                                      | Fenwick tree for prefix queries and point updates                   | O(log n) updates/queries                 | Range sum, inversion count             |
| greedy-algorithms/                                 | Greedy algorithms with proof-of-correctness frameworks               | Local optimality, sorting strategies      | Activity selection, interval partition |
| conceptual-exercises/                              | Conceptual exercises and algorithmic thought experiments             | Varied                                   | Problem brainstorming                 |
| implementation-tips/                               | Practical insights, heuristics, and implementation tips              | Performance tuning, memory considerations | Cache-friendly coding                  |
| segment-trees/                                     | Segment tree and lazy propagation techniques                        | Interval trees, lazy updates              | Range sum, range update                |
| stack-recursion/                                   | Stack-based solutions and recursive simulation                      | LIFO operations, recursion management     | Next greater element, DFS simulation   |
| prefix-trees/                                      | Trie (prefix tree) implementations for string algorithms             | O(L) per operation, memory trade-offs    | Autocomplete, prefix queries           |
| graph-algorithms/                                  | Graph traversal and shortest path algorithms                        | BFS, DFS, Dijkstra                       | Shortest path, cycle detection         |
| histogram-techniques/                              | Largest rectangle in histogram and monotonic stack optimizations     | Monotonic stack                          | Max histogram area                     |
| leetcode-solutions/                                | Curated LeetCode problem solutions with links                       | Varied                                   | LeetCode 2-sum, median find            |
| math-utilities/                                    | Number theory utilities and mathematical problem solving             | GCD, sieve, modular arithmetic           | Prime sieve, modular exponentiation     |
| strongly-connected-components/                     | Strongly Connected Components using Kosaraju and Tarjan             | O(V+E) algorithms                        | SCC decomposition                      |
| advanced-segment-trees/                            | Advanced segment tree variants (persistent, merge sort tree)        | Segment trees, persistence               | Dynamic range queries                  |
| string-algorithms/                                 | String algorithms: KMP, Z-algo, Rabin-Karp                          | O(n) pattern search, rolling hash        | Pattern matching                       |
| optimized-shortest-paths/                          | Supernode optimizations for multi-source shortest path problems      | Graph compression, Dijkstra              | Speed-optimized Dijkstra               |
| code-templates/                                    | Reusable C++ templates and helper classes                           | Fast IO, macros, utility functions       | Template library                       |
| dag-ordering/                                      | Topological sorting in Directed Acyclic Graphs                      | Kahn's algorithm, DFS order              | Task scheduling, dependency resolution  |
| tree-algorithms/                                   | Tree algorithms: traversals, LCA, diameter                          | DFS, BFS, binary lifting                 | Tree diameter, distance queries         |
| two-pointer-techniques/                            | Two-pointer sliding window and partitioning techniques              | O(n) scan, window adjustments             | 2-sum, subarray sum                    |
| backtracking-solutions/                            | Backtracking and branch-and-bound search                             | Exponential search, pruning              | N-Queens, subset generation            |
| fundamentals/, binary-tree-foundations/, bit-manipulation/, contribution-techniques/ | Utility snippets and foundational techniques                         | Fast IO, bit operations, tree setup      | Code snippets                          |

## Root Problem Solutions

Problems are now organized by category in the `problems/` directory:

### Problems by Difficulty Level

| Directory | Description |
|-----------|-------------|
| `problems/A/` | A-level problems (e.g., A_Boredom, A_Median_of_an_Array, A_Row_GCD) |
| `problems/B/` | B-level problems (e.g., B_Choosing_Cubes, B_Make_Array_Good) |
| `problems/C/` | C-level problems (e.g., C_Palindromic_Subsequences, C_Set_or_Decrease) |
| `problems/D/` | D-level problems (e.g., D_Beautiful_Array, D_Carousel) |
| `problems/E/` | E-level problems (e.g., E_Money_Buys_Happiness, E_Two_Arrays_and_Sum_of_Functions) |
| `problems/F/` | F-level problems (e.g., F_Ira_and_Flamenco, F_Group_Projects) |
| `problems/G/` | G-level problems (e.g., G_Yasya_and_the_Mysterious_Tree) |

### Miscellaneous Problems

Other problems are categorized by topic:

| Directory | Description |
|-----------|-------------|
| `problems/Miscellaneous/Tree-Problems/` | Tree-related problems (e.g., Tree_Diameter, Subordinates) |
| `problems/Miscellaneous/Range-Queries/` | Range query problems (e.g., Range_Xor_Queries, Increasing_Array_Queries) |
| `problems/Miscellaneous/Math/` | Mathematical problems (e.g., Common_Divisors, Counting_Coprime_Pairs) |
| `problems/Miscellaneous/Dynamic-Programming/` | DP problems (e.g., Required_Substring) |
| `problems/Miscellaneous/Utility/` | Utility code and miscellaneous problems |

## Sample Input/Output

- `input.txt`: Sample input for testing.
- `output.txt`: Expected output.

## Usage

To compile and run any solution:

```bash
# Compile
g++ -std=c++17 <filename>.cpp -o <executable>

# Run with sample input
echo "< input.txt" | ./<executable>
```

You can also configure VS Code tasks for one-click build and run.

## Contributing

1. Fork this repository.
2. Create a branch: `git checkout -b feature/YourProblem`.
3. Add your solution in the appropriate directory or root.
4. Name files using the `<Letter>_ProblemName.cpp` format.
5. Submit a pull request with a clear problem description and solution approach.

## License

This project currently has no license specified. Please contact the repository owner for licensing details.
