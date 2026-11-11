#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: 0-1 BFS (Shortest Path with Edge Weights 0 or 1)
 *
 * WHY 0-1 BFS?
 * - Standard Dijkstra takes O((V + E) log V).
 * - When all edge weights are ONLY 0 or 1, we can use std::deque to achieve O(V + E) linear time!
 * - If weight is 0: push to FRONT of deque (no added cost).
 * - If weight is 1: push to BACK of deque (+1 cost).
 *
 * EXTREMELY COMMON IN OA:
 * - Grid path problems where turning or changing directions costs 1, and going straight costs 0.
 * - LeetCode 1368, LeetCode 2290.
 */

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;

vector<pair<int, int>> adj[MAXN]; // {neighbor, weight (0 or 1)}
int dist[MAXN];

void bfs_01(int start, int n) {
    for (int i = 1; i <= n; i++) dist[i] = INF;

    deque<int> dq;
    dist[start] = 0;
    dq.push_back(start);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
}

void solve() {
    int n, m, start_node;
    if (!(cin >> n >> m >> start_node)) return;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // w is either 0 or 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    bfs_01(start_node, n);

    cout << "0-1 BFS Distances from " << start_node << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "To " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << "\n";
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

