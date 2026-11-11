# Bridges, Articulation Points & Strongly Connected Components (SCC)

## Core Concepts

### Bridges (Critical Edges)
An edge $(u, v)$ whose removal disconnects the graph.
- Condition: `low[v] > tin[u]` (no back-edge from $v$ or below can reach $u$ or above).

### Articulation Points (Cut Vertices)
A vertex whose removal disconnects the graph.
- Condition (non-root): `low[v] >= tin[u]` for some child $v$.
- Condition (root of DFS tree): has $\ge 2$ children in the DFS tree.

### Strongly Connected Components (SCC)
In directed graphs, an SCC is a maximal subgraph where every vertex is reachable from every other vertex.
- Algorithms: **Tarjan's Algorithm** or **Kosaraju's Algorithm** in $O(V + E)$.

## Problems to Practice
- LeetCode 1192: Critical Connections in a Network (Bridges)
- CSES Graph Algorithms: Flight Routes Check
- CSES Graph Algorithms: Planets and Kingdoms

