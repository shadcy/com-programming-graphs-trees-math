#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

/*
 * PROBLEM: Re-rooting DP (Tree Distances / Sum of Distances in Tree)
 * 
 * DESCRIPTION:
 * For each node in a tree with N nodes, compute the sum of distances from it to all other nodes.
 *
 * NAIVE APPROACH: Run BFS/DFS from every node -> O(N^2) => TLE for N = 10^5.
 *
 * RE-ROOTING TECHNIQUE: O(N)
 * Step 1: Pick an arbitrary root (node 1). Compute:
 *   - sz[u]: size of subtree rooted at u
 *   - dp[u]: sum of distances from u to all nodes in its subtree
 *
 * Step 2: Push answers down to children:
 *   When shifting root from parent 'u' to child 'v':
 *   - All nodes in v's subtree get 1 step CLOSER: -sz[v]
 *   - All remaining nodes (N - sz[v]) get 1 step FARTHER: +(N - sz[v])
 *   Transition: ans[v] = ans[u] - sz[v] + (N - sz[v])
 *
 * TOTAL TIME: O(N)
 * TOTAL SPACE: O(N)
 */

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll sz_subtree[MAXN];
ll dp_down[MAXN];
ll ans[MAXN];
int N;

// Step 1: Bottom-up DFS to compute subtree sizes and dp_down
void dfs1(int u, int p) {
    sz_subtree[u] = 1;
    dp_down[u] = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            sz_subtree[u] += sz_subtree[v];
            dp_down[u] += dp_down[v] + sz_subtree[v];
        }
    }
}

// Step 2: Top-down DFS to push answers to children
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            // Re-root transition from u to v
            ans[v] = ans[u] - sz_subtree[v] + (N - sz_subtree[v]);
            dfs2(v, u);
        }
    }
}

void solve() {
    if (!(cin >> N)) return;

    for (int i = 1; i <= N; i++) adj[i].clear();

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);

    // Root answer at node 1 is its dp_down value
    ans[1] = dp_down[1];

    dfs2(1, 0);

    cout << "Sum of distances from each node:\n";
    for (int i = 1; i <= N; i++) {
        cout << "Node " << i << ": " << ans[i] << "\n";
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

