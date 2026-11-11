#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Connected Components & Bipartite Graph Check (2-Coloring)
 *
 * KEY CONCEPTS:
 * 1. A graph is BIPARTITE if and only if it contains NO ODD-LENGTH CYCLES.
 * 2. 2-Coloring: Color nodes using 0 and 1. If an adjacent neighbor already has the same color,
 *    the graph is NOT bipartite.
 * 3. Connected Components: Count how many separate components exist by initiating DFS from all unvisited nodes.
 *
 * TIME COMPLEXITY: O(V + E)
 * SPACE COMPLEXITY: O(V + E)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int color[MAXN]; // -1 = unvisited, 0 or 1 = colors
int component_id[MAXN];

bool bfs_check_bipartite(int start, int comp_id) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    component_id[start] = comp_id;

    bool is_bipartite = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u]; // Alternate color
                component_id[v] = comp_id;
                q.push(v);
            } else if (color[v] == color[u]) {
                // Same color found on an adjacent node -> Odd cycle!
                is_bipartite = false;
            }
        }
    }
    return is_bipartite;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = -1;
        component_id[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    bool overall_bipartite = true;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            components++;
            if (!bfs_check_bipartite(i, components)) {
                overall_bipartite = false;
            }
        }
    }

    cout << "Total Connected Components: " << components << "\n";
    cout << "Is Graph Bipartite (2-Colorable): " << (overall_bipartite ? "YES" : "NO") << "\n";
    if (overall_bipartite) {
        cout << "Color assignments (Node: Color):\n";
        for (int i = 1; i <= n; i++) {
            cout << i << ": " << color[i] << " | Component: " << component_id[i] << "\n";
        }
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

