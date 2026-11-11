#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Lowest Common Ancestor (LCA) using Binary Lifting
 * 
 * CORE IDEA:
 * Any integer k can be represented as a sum of powers of 2 (binary representation).
 * Instead of jumping one step at a time (which takes O(N) per query), we precompute
 * jumps of size 2^0, 2^1, 2^2, ..., 2^LOG.
 *
 * up[u][k] = 2^k-th ancestor of node u.
 * Recurrence: up[u][k] = up[ up[u][k - 1] ][k - 1]
 *
 * COMPLEXITY:
 * Preprocessing: O(N log N)
 * LCA Query: O(log N)
 * Distance Query: O(log N)
 */

const int MAXN = 2e5 + 5;
const int LOG = 20; // 2^19 > 5e5

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;

    for (int k = 1; k < LOG; k++) {
        if (up[u][k - 1] != 0) {
            up[u][k] = up[up[u][k - 1]][k - 1];
        } else {
            up[u][k] = 0;
        }
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

// Returns the k-th ancestor of node u
int get_kth_ancestor(int u, int k) {
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1) {
            u = up[u][i];
            if (u == 0) break;
        }
    }
    return u;
}

// Returns LCA of u and v in O(log N)
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // 1. Bring u and v to the same depth
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    // 2. Jump together in decreasing powers of 2
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // Their direct parent is the LCA
    return up[u][0];
}

// Distance between two nodes on tree
int get_distance(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Root tree at node 1
    dfs(1, 0, 0);

    cout << "--- LCA and Distance Queries ---\n";
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ancestor = lca(u, v);
        int d = get_distance(u, v);
        cout << "LCA(" << u << ", " << v << ") = " << ancestor 
             << " | Distance = " << d << "\n";
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

