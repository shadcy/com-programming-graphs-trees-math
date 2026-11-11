#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

/*
 * PROBLEM: Subtree Sum Queries via Euler Tour + Fenwick Tree (BIT)
 *
 * THE MAGIC OF EULER TOUR:
 * By tracking entry time (tin[u]) and exit time (tout[u]) during DFS,
 * the entire subtree of any node u becomes a CONTIGUOUS RANGE:
 * [tin[u], tout[u]]
 *
 * Therefore:
 * - Subtree sum query on node u = Range sum query on [tin[u], tout[u]]!
 * - Point update on node u = Point update at index tin[u]!
 *
 * Using Fenwick Tree (BIT):
 * Point Update: O(log N)
 * Subtree Query: O(log N)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll val[MAXN];
int tin[MAXN], tout[MAXN];
int timer = 0;
int N, Q;

// Fenwick Tree (Binary Indexed Tree) for range sum queries
struct Fenwick {
    int size;
    vector<ll> tree;
    Fenwick(int n) : size(n), tree(n + 1, 0) {}

    void update(int i, ll delta) {
        for (; i <= size; i += (i & -i))
            tree[i] += delta;
    }

    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= (i & -i))
            sum += tree[i];
        return sum;
    }

    ll queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void dfs(int u, int p) {
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

void solve() {
    if (!(cin >> N >> Q)) return;

    for (int i = 1; i <= N; i++) {
        cin >> val[i];
        adj[i].clear();
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer = 0;
    dfs(1, 0);

    Fenwick bit(N);
    // Initialize Fenwick tree at tin[i] with value val[i]
    for (int i = 1; i <= N; i++) {
        bit.update(tin[i], val[i]);
    }

    cout << "--- Processing Queries ---\n";
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Update node u to new_val
            int u;
            ll new_val;
            cin >> u >> new_val;
            ll delta = new_val - val[u];
            val[u] = new_val;
            bit.update(tin[u], delta);
            cout << "Updated node " << u << " to " << new_val << "\n";
        } else {
            // Query subtree sum of node u
            int u;
            cin >> u;
            ll subtree_sum = bit.queryRange(tin[u], tout[u]);
            cout << "Subtree sum of node " << u << " = " << subtree_sum << "\n";
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

