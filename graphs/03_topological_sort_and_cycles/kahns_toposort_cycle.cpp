#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Kahn's Algorithm for Topological Sort & Directed Cycle Detection
 * (Directly solves Course Schedule I & II, Alien Dictionary)
 *
 * HOW IT WORKS:
 * 1. Compute in-degree for every vertex (number of incoming directed edges).
 * 2. Push all vertices with in-degree == 0 into a queue (they have no prerequisites).
 * 3. While queue is not empty:
 *    - Pop u, append to topological order.
 *    - For every outgoing edge (u -> v), decrement in-degree[v].
 *    - If in-degree[v] becomes 0, push v into queue.
 * 4. If the number of processed nodes == N, the graph is a DAG (Directed Acyclic Graph)
 *    and a valid topological order exists.
 *    OTHERWISE, the graph contains a DIRECTED CYCLE!
 *
 * TIME COMPLEXITY: O(V + E)
 * SPACE COMPLEXITY: O(V + E)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int in_degree[MAXN];

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        in_degree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v; // Directed edge u -> v (u is prerequisite for v)
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if ((int)topo_order.size() == n) {
        cout << "Valid Topological Sort Exists (Graph is a DAG):\n";
        for (int i = 0; i < n; i++) {
            cout << topo_order[i] << (i + 1 < n ? " -> " : "\n");
        }
    } else {
        cout << "CYCLE DETECTED! Cannot complete topological sort.\n";
        cout << "Nodes processed: " << topo_order.size() << " / " << n << "\n";
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

