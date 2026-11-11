# Euler Tour & Subtree Queries

## Concept
The **Euler Tour Technique** (flattening a tree) assigns each node an entry time `tin[u]` and exit time `tout[u]` during a DFS.
- Every node in the subtree of $u$ has its discovery time inside $[\text{tin}[u], \text{tout}[u]]$.
- This converts arbitrary tree subtree problems into standard **1D array range queries**!

## Data Structures Used
- **Fenwick Tree (BIT)** for point update and range sum in $O(\log N)$.
- **Segment Tree** for range minimum/maximum/GCD/lazy updates in $O(\log N)$.

## Problems to Practice
- CSES Tree Algorithms: Subtree Queries
- Codeforces 383C: Propagating tree
- Codeforces 620E: New Year Tree

