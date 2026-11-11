# Topological Sort & Cycle Detection

## Core Rules
- **Topological Sorting** is only possible for **DAGs (Directed Acyclic Graphs)**.
- If there is any directed cycle, no topological ordering exists.
- **Kahn's Algorithm (BFS)** uses in-degrees. If total nodes processed $< N$, a cycle exists!
- **DFS Approach (3-Coloring)**:
  - White (0): Unvisited
  - Grey (1): In current recursion stack. If encountered, **BACK-EDGE FOUND -> CYCLE**!
  - Black (2): Fully visited and exited.

## Problems to Practice
- LeetCode 207: Course Schedule
- LeetCode 210: Course Schedule II
- LeetCode 269: Alien Dictionary
- CSES Graph Algorithms: Course Schedule

