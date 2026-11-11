#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Bridges and Articulation Points (Tarjan's Algorithm)
 * (Directly solves LeetCode 1192: Critical Connections in a Network)
 *
 * DEFINITIONS:
 * - Bridge: An edge whose removal increases the number of connected components.
 * - Articulation Point (Cut Vertex): A vertex whose removal increases the number of connected components.
 *
 * KEY ARRAYS:
 * - tin[u]: Discovery / entry time of node u during DFS.
 * - low[u]: Lowest tin reachable from u using tree edges and at most one back-edge.
 *
 * CONDITIONS:
 * - Edge (u, v) is a BRIDGE if: low[v] > tin[u]
 *   (Meaning v has no back-edge reaching u or above u)
 * - Node u is an ARTICULATION POINT if:
 *   1. u is the root of DFS tree and has >= 2 children.
 *   2. u is NOT root and has a child v such that: low[v] >= tin[u].
 *
 * TIME COMPLEXITY: O(V + E)
 * SPACE COMPLEXITY: O(V + E)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN];
bool visited[MAXN];
bool is_cut_vertex[MAXN];
vector<pair<int, int>> bridges;
int timer = 0;

void dfs(int u, int p) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == p) continue; // Skip direct parent edge
        if (visited[v]) {
            // Back-edge
            low[u] = min(low[u], tin[v]);
        } else {
            // Tree edge
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            children++;

            // Bridge condition
            if (low[v] > tin[u]) {
                bridges.push_back({u, v});
            }

            // Cut vertex condition (non-root)
            if (p != 0 && low[v] >= tin[u]) {
                is_cut_vertex[u] = true;
            }
        }
    }

    // Cut vertex condition (root of DFS tree)
    if (p == 0 && children > 1) {
        is_cut_vertex[u] = true;
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
        is_cut_vertex[i] = false;
    }
    bridges.clear();
    timer = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    cout << "--- Bridges (Critical Connections) ---\n";
    cout << "Total Bridges: " << bridges.size() << "\n";
    for (auto& b : bridges) {
        cout << b.first << " - " << b.second << "\n";
    }

    cout << "\n--- Articulation Points (Cut Vertices) ---\n";
    vector<int> cuts;
    for (int i = 1; i <= n; i++) {
        if (is_cut_vertex[i]) cuts.push_back(i);
    }
    cout << "Total Cut Vertices: " << cuts.size() << "\n";
    for (int u : cuts) {
        cout << u << " ";
    }
    cout << "\n";
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

