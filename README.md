# Competitive Programming (CP) & OA Practice Workspace

Your complete C++ Competitive Programming workspace is organized and optimized for Online Assessments (OA) at top tech companies.

---

## ⚡ Quick Start

### 1. Build & Run Any Solution in 1 Key:
- Open any `.cpp` file in `trees/`, `graphs/`, or the root.
- Press **`Ctrl + Shift + B`** (Default Build Shortcut).
  - Automatically compiles with **`-std=c++17 -O2 -Wall -DLOCAL`**.
  - Feeds the folder's `input.txt` into the program.
  - Generates `output.txt`, prints the result, and displays the execution time in **milliseconds** (to verify time limits).

### 2. Run from the Terminal:
```powershell
# Run the active / newest solution:
.\run.ps1

# Or specify any file:
.\run.ps1 trees/01_traversals_and_properties/tree_diameter.cpp
.\run.ps1 graphs/02_shortest_paths/dijkstra.cpp
```

### 3. Debug with Breakpoints (GDB):
- Set a breakpoint on any line.
- Press **`F5`** to launch GDB and step through variables and loops.

---

## 🌲 Trees Sub-Problem Hub (`trees/`)

See [`trees/README.md`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/README.md) for theory and curated questions.

- [`01_traversals_and_properties/`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/01_traversals_and_properties/):
  - [`tree_diameter.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/01_traversals_and_properties/tree_diameter.cpp): 2-DFS/BFS Tree Diameter $O(N)$.
  - [`tree_traversals.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/01_traversals_and_properties/tree_traversals.cpp): Subtree sizes, Depths, Heights, BFS level-order.
- [`02_lowest_common_ancestor/`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/02_lowest_common_ancestor/):
  - [`lca_binary_lifting.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/02_lowest_common_ancestor/lca_binary_lifting.cpp): Binary Lifting LCA & $k$-th ancestor queries in $O(\log N)$.
- [`03_tree_dp/`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/03_tree_dp/):
  - [`rerooting_dp.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/03_tree_dp/rerooting_dp.cpp): In-Out Re-rooting DP in $O(N)$ (Tree Distances).
  - [`subtree_dp.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/03_tree_dp/subtree_dp.cpp): Maximum Weight Independent Set (House Robber III on trees).
- [`04_binary_search_trees/`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/04_binary_search_trees/):
  - [`bst_operations_and_kth.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/04_binary_search_trees/bst_operations_and_kth.cpp): BST Insert, Range Validate, Inorder $k$-th smallest.
- [`05_euler_tour_and_subtree_queries/`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/05_euler_tour_and_subtree_queries/):
  - [`euler_tour_subtree_queries.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/trees/05_euler_tour_and_subtree_queries/euler_tour_subtree_queries.cpp): Tree flattening + Fenwick (BIT) for subtree range queries.

---

## 🕸️ Graphs Sub-Problem Hub (`graphs/`)

See [`graphs/README.md`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/README.md) for theory and curated questions.

- [`01_traversals_and_components/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/01_traversals_and_components/):
  - [`bfs_dfs_bipartite.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/01_traversals_and_components/bfs_dfs_bipartite.cpp): 2-Coloring Bipartite check & Connected Components $O(V + E)$.
- [`02_shortest_paths/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/02_shortest_paths/):
  - [`dijkstra.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/02_shortest_paths/dijkstra.cpp): Dijkstra with min-heap priority queue $O((V + E) \log V)$.
  - [`bfs_01.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/02_shortest_paths/bfs_01.cpp): 0-1 BFS with `std::deque` in linear $O(V + E)$.
- [`03_topological_sort_and_cycles/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/03_topological_sort_and_cycles/):
  - [`kahns_toposort_cycle.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/03_topological_sort_and_cycles/kahns_toposort_cycle.cpp): In-degree BFS Topological Sort & DAG cycle detection.
- [`04_mst_and_dsu/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/04_mst_and_dsu/):
  - [`kruskal_mst.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/04_mst_and_dsu/kruskal_mst.cpp): Kruskal's Minimum Spanning Tree with DSU.
- [`05_grid_graphs_and_multisource_bfs/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/05_grid_graphs_and_multisource_bfs/):
  - [`grid_multisource_bfs.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/05_grid_graphs_and_multisource_bfs/grid_multisource_bfs.cpp): Multi-source BFS on 2D matrices (Rotting Oranges).
- [`06_bridges_and_scc/`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/06_bridges_and_scc/):
  - [`bridges_articulation_points.cpp`](file:///c:/Users/Asus/Desktop/PR_1/CP/graphs/06_bridges_and_scc/bridges_articulation_points.cpp): Tarjan's Critical Connections & Cut Vertices in $O(V + E)$.

---

## 💡 Code Snippets (Type & Press `Tab`)

In any `.cpp` file:
- `cp` $\rightarrow$ Complete CP boilerplate with fast I/O and `solve()`.
- `dijkstra` $\rightarrow$ Dijkstra shortest path snippet.
- `dsu` $\rightarrow$ Disjoint Set Union class.
- `bsans` $\rightarrow$ Binary search on answer predicate pattern.
- `binpow` $\rightarrow$ Fast modular exponentiation.
- `ncr` $\rightarrow$ Precomputed factorials for $O(1)$ combinations.
- `sieve` $\rightarrow$ Prime sieve up to $N$.
