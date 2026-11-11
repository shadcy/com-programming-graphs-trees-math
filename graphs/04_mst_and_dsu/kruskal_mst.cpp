#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

/*
 * PROBLEM: Minimum Spanning Tree (MST) using Kruskal's Algorithm & DSU
 *
 * KRUSKAL'S GREEDY STRATEGY:
 * 1. Sort all edges in non-decreasing order of weights.
 * 2. Iterate through sorted edges:
 *    - If endpoints u and v belong to different components (checked via DSU.find),
 *      add this edge to the MST and merge components (DSU.unite).
 *    - If they already belong to the same component, skip the edge (adding it would create a cycle).
 * 3. Stop when (N - 1) edges are added, or when all edges are checked.
 *
 * TIME COMPLEXITY:
 * Sorting edges: O(E log E)
 * DSU operations: O(E * alpha(V)) approx O(E)
 * Total: O(E log E)
 *
 * SPACE COMPLEXITY: O(V + E)
 */

struct Edge {
    int u, v;
    ll weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank_val;
    int components;
    DSU(int n) : parent(n + 1), rank_val(n + 1, 0), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return false;

        // Union by rank
        if (rank_val[root_i] < rank_val[root_j]) swap(root_i, root_j);
        parent[root_j] = root_i;
        if (rank_val[root_i] == rank_val[root_j]) rank_val[root_i]++;
        components--;
        return true;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    ll total_mst_weight = 0;
    vector<Edge> mst_edges;

    // Step 2: Greedily add edges
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_mst_weight += edge.weight;
            mst_edges.push_back(edge);
            if ((int)mst_edges.size() == n - 1) break;
        }
    }

    if ((int)mst_edges.size() == n - 1) {
        cout << "MST Successfully Formed!\n";
        cout << "Total MST Cost: " << total_mst_weight << "\n";
        cout << "MST Edges included:\n";
        for (auto& e : mst_edges) {
            cout << e.u << " - " << e.v << " (weight: " << e.weight << ")\n";
        }
    } else {
        cout << "Graph is DISCONNECTED. Cannot form Spanning Tree.\n";
    }
}

int main() {
    FAST_IO;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

