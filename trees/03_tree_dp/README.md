# Tree Dynamic Programming (Tree DP)

## Two Major Tree DP Paradigms

### 1. Subtree DP (Bottom-Up)
Information flows from leaves to the root.
- Typical State: `dp[u]` depends only on `dp[v]` for all children $v$ of $u$.
- Examples: Subtree sizes, Maximum Weight Independent Set (House Robber III), Tree Knapsack.

### 2. Re-rooting DP (In-Out DP)
Used when a problem asks to compute an answer *for every single node as the root*, and doing so naively takes $O(N^2)$.
- Step 1: Compute answers for an arbitrary root (node 1) in $O(N)$.
- Step 2: Use a second DFS to compute how the answer transitions when shifting the root from parent to child in $O(1)$.
- Total Time: $O(N)$.

## Problems to Practice
- LeetCode 834: Sum of Distances in Tree
- LeetCode 337: House Robber III
- CSES Tree Algorithms: Tree Distances I & II
- Codeforces 1187E: Tree Painting

