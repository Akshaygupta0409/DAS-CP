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

Each folder in the root corresponds to a topic or technique:

- `4_star_problem/`: Hard problems requiring advanced combinatorial and optimization techniques.
- `Binary_search/`: Binary search patterns (O(log n)).
- `DSU/`: Disjoint Set Union (Union-Find) implementations with path compression.
- `Dynamic_programing/`: Dynamic programming (memoization & bottom-up).
- `Fenwick_tree(aka bit)/`: Fenwick Tree implementations for range queries/updates.
- `Greedy/`: Greedy algorithms and correctness proofs.
- `Ideas/`: Conceptual exercises and thought experiments.
- `Observations/`: Practical insights and heuristics.
- `Range_maintanence/`: Segment tree and lazy propagation techniques.
- `Stack/`: Stack applications and recursion simulation.
- `Tries/`: Trie (prefix tree) implementations for string algorithms.
- `graph/`: Graph algorithms (DFS, BFS, Dijkstra, spanning trees).
- `histogramidea/`: Variations of the largest rectangle in histogram problem.
- `lccodes/`: Solutions to LeetCode problems.
- `maths/`: Number theory and mathematical problem solving.
- `scc/`: Strongly Connected Components (Kosaraju, Tarjan).
- `segmenttree/`: Advanced segment tree variants.
- `string/`: String processing and pattern matching.
- `suprenode_dijkastra/`: Supernode optimizations for Dijkstra.
- `templates/`: Common C++ templates and helper classes.
- `topological_sort/`: Topological sorting in DAGs.
- `tree/`: Tree traversal, diameter, and distance algorithms.
- `two_pointer/`: Two-pointer technique problems.
- `backtracking/`: Backtracking and brute-force search patterns.
- `basics/`, `binary_tree/`, `bitmanipulation/`, `contributation-technique/`: Utility snippets and foundational techniques.

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
