# Lowest Common Ancestor (LCA) & Binary Lifting

## Why Binary Lifting?
- Naive LCA takes $O(N)$ per query by walking parents.
- With $Q$ queries up to $10^5$, naive takes $O(N \times Q) \approx 10^{10}$ operations (TLE).
- Binary lifting preprocesses jumps in $O(N \log N)$ and answers each query in $O(\log N)$.

## Formulas
- $\text{dist}(u, v) = \text{depth}[u] + \text{depth}[v] - 2 \times \text{depth}[\text{LCA}(u, v)]$
- Check if $u$ is ancestor of $v$: $\text{tin}[u] \le \text{tin}[v]$ and $\text{tout}[u] \ge \text{tout}[v]$ (Euler Tour technique).

## Problems to Practice
- LeetCode 236: Lowest Common Ancestor of a Binary Tree
- LeetCode 1483: Kth Ancestor of a Tree Node
- CSES Tree Algorithms: Company Queries I & II
- CSES Tree Algorithms: Distance Queries

