#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

/*
 * PROBLEM: Single-Source Shortest Path (Dijkstra's Algorithm)
 *
 * PRECONDITION:
 * Edge weights MUST be non-negative (w >= 0).
 *
 * IMPLEMENTATION DETAILS:
 * - Uses std::priority_queue with greater<pair<ll, int>> (min-heap).
 * - Distances tracked in 64-bit integer (ll) to prevent integer overflow.
 * - Distance check `if (d > dist[u]) continue;` skips outdated states.
 * - Reconstructs shortest path using parent array.
 *
 * TIME COMPLEXITY: O((V + E) log V)
 * SPACE COMPLEXITY: O(V + E)
 */

const int MAXN = 2e5 + 5;
const ll LINF = 1e18 + 7;

vector<pair<int, ll>> adj[MAXN];
ll dist[MAXN];
int parent_node[MAXN];

void dijkstra(int start, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = LINF;
        parent_node[i] = -1;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent_node[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Reconstruct path from start to target
vector<int> get_path(int target) {
    vector<int> path;
    if (dist[target] == LINF) return path;

    for (int curr = target; curr != -1; curr = parent_node[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    int n, m, start_node;
    if (!(cin >> n >> m >> start_node)) return;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Directed? Remove this line.
    }

    dijkstra(start_node, n);

    cout << "Shortest distances from source " << start_node << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "To Node " << i << ": ";
        if (dist[i] == LINF) cout << "UNREACHABLE\n";
        else {
            cout << dist[i] << " | Path: ";
            vector<int> path = get_path(i);
            for (size_t j = 0; j < path.size(); j++) {
                cout << path[j] << (j + 1 < path.size() ? " -> " : "\n");
            }
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

