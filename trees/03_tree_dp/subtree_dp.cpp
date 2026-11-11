#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

/*
 * PROBLEM: Maximum Weight Independent Set on a Tree
 * (Equivalent to LeetCode 337: House Robber III)
 *
 * DESCRIPTION:
 * Given a tree with weights on each node, select a subset of nodes such that
 * no two selected nodes are adjacent, and the sum of weights is maximized.
 *
 * DP STATE:
 * dp[u][0] = Maximum weight in subtree of u if u is NOT selected.
 * dp[u][1] = Maximum weight in subtree of u if u IS selected.
 *
 * TRANSITIONS:
 * If u is NOT selected: children v can either be selected or not selected.
 *   dp[u][0] = sum( max(dp[v][0], dp[v][1]) )
 *
 * If u IS selected: children v CANNOT be selected.
 *   dp[u][1] = weight[u] + sum( dp[v][0] )
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(N)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll val[MAXN];
ll dp[MAXN][2];

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = val[u];

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            // If u is not chosen, v can be chosen or not
            dp[u][0] += max(dp[v][0], dp[v][1]);
            // If u is chosen, v cannot be chosen
            dp[u][1] += dp[v][0];
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    ll max_weight = max(dp[1][0], dp[1][1]);
    cout << "Maximum Independent Set Weight: " << max_weight << "\n";
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

