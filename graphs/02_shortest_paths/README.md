# Shortest Path Algorithms

## Comparison Table

| Algorithm | Edge Weights | Time Complexity | Use Case |
| :--- | :--- | :--- | :--- |
| **Standard BFS** | Unweighted (all = 1) | $O(V + E)$ | Minimum hops / level steps |
| **0-1 BFS** | 0 or 1 | $O(V + E)$ | Minimum flips / directional shifts |
| **Dijkstra** | Non-negative ($w \ge 0$) | $O((V + E) \log V)$ | General non-negative weighted graphs |
| **Bellman-Ford** | Any (detects negative cycles) | $O(V \times E)$ | Negative weights present |
| **Floyd-Warshall**| Any (All pairs shortest path) | $O(V^3)$ | All-pairs, small graphs ($V \le 400$) |

## Problems to Practice
- LeetCode 743: Network Delay Time
- LeetCode 1368: Minimum Cost to Make at Least One Valid Path in a Grid (0-1 BFS)
- LeetCode 1631: Path With Minimum Effort
- CSES Graph Algorithms: Shortest Routes I & II

