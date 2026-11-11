# Minimum Spanning Tree (MST) & Disjoint Set Union (DSU)

## Key Concepts
- **Spanning Tree**: A subgraph that connects all $V$ vertices with exactly $V - 1$ edges and no cycles.
- **Kruskal's Algorithm**: Sort all edges by weight, add edge if it connects different components using DSU.
- **DSU (Disjoint Set Union)**:
  - Path compression: Flatten parent pointers during find.
  - Union by rank/size: Attach smaller tree to root of larger tree.
  - Amortized complexity per operation: $O(\alpha(V)) \approx O(1)$ nearly constant.

## Problems to Practice
- LeetCode 1584: Min Cost to Connect All Points
- LeetCode 684: Redundant Connection
- LeetCode 721: Accounts Merge
- CSES Graph Algorithms: Road Reparation

