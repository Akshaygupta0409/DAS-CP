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
| 4_star_problem/                                    | Hard combinatorial & optimization puzzles                           | Combinatorics, DFS, heuristic pruning     | 4-sum, advanced DP                     |
| Binary_search/                                     | Classic and parametric binary search techniques                     | O(log n), boundary conditions            | First/last occurrence search           |
| DSU/                                               | Dynamic connectivity using Union-Find                                | Union by rank, path compression          | Connected components                   |
| Dynamic_programing/                                | Top-down and bottom-up dynamic programming                          | Memoization, state transition            | Knapsack, LIS                          |
| Fenwick_tree(aka bit)/                             | Fenwick tree for prefix queries and point updates                   | O(log n) updates/queries                 | Range sum, inversion count             |
| Greedy/                                            | Greedy algorithms with proof-of-correctness frameworks               | Local optimality, sorting strategies      | Activity selection, interval partition |
| Ideas/                                             | Conceptual exercises and algorithmic thought experiments             | Varied                                   | Problem brainstorming                  |
| Observations/                                      | Practical insights, heuristics, and implementation tips              | Performance tuning, memory considerations | Cache-friendly coding                  |
| Range_maintanence/                                 | Segment tree and lazy propagation techniques                        | Interval trees, lazy updates              | Range sum, range update                |
| Stack/                                             | Stack-based solutions and recursive simulation                      | LIFO operations, recursion management     | Next greater element, DFS simulation   |
| Tries/                                             | Trie (prefix tree) implementations for string operations            | O(L) per operation, memory trade-offs    | Autocomplete, prefix queries           |
| graph/                                             | Graph traversal and shortest path algorithms                        | BFS, DFS, Dijkstra                       | Shortest path, cycle detection         |
| histogramidea/                                     | Largest rectangle in histogram and monotonic stack optimizations    | Monotonic stack                          | Max histogram area                     |
| lccodes/                                           | Curated LeetCode problem solutions with links                       | Varied                                   | LeetCode 2-sum, median find            |
| maths/                                             | Number theory utilities and mathematical problem solving            | GCD, sieve, modular arithmetic           | Prime sieve, modular exponentiation     |
| scc/                                               | Strongly Connected Components using Kosaraju and Tarjan            | O(V+E) algorithms                        | SCC decomposition                      |
| segmenttree/                                       | Advanced segment tree variants (persistent, merge sort tree)        | Segment trees, persistence               | Dynamic range queries                  |
| string/                                            | String algorithms: KMP, Z-algo, Rabin-Karp                          | O(n) pattern search, rolling hash        | Pattern matching                       |
| suprenode_dijkastra/                               | Supernode optimizations for multi-source shortest path problems     | Graph compression, Dijkstra              | Speed-optimized Dijkstra               |
| templates/                                         | Reusable C++ templates and helper classes                           | Fast IO, macros, utility functions       | Template library                       |
| topological_sort/                                  | Topological sorting in Directed Acyclic Graphs                       | Kahn's algorithm, DFS order              | Task scheduling, dependency resolution  |
| tree/                                              | Tree algorithms: traversals, LCA, diameter                         | DFS, BFS, binary lifting                 | Tree diameter, distance queries         |
| two_pointer/                                       | Two-pointer sliding window and partitioning techniques              | O(n) scan, window adjustments             | 2-sum, subarray sum                    |
| backtracking/                                      | Backtracking and branch-and-bound search                             | Exponential search, pruning              | N-Queens, subset generation            |
| basics/, binary_tree/, bitmanipulation/, contributation-technique/ | Utility snippets and foundational techniques                         | Fast IO, bit operations, tree setup      | Code snippets                          |

## Root Problem Solutions

Standalone files in the root directory follow the naming convention `<Letter>_<ProblemName>.cpp`, for example:

- `A_Boredom.cpp`
- `B_Choosing_Cubes.cpp`
- `C_Palindromic_Subsequences.cpp`
- ...and many more

Executables (`.exe`) generated from these files are also present.

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
