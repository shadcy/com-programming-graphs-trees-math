#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Tree Diameter
 * 
 * DESCRIPTION:
 * The diameter of a tree is the maximum distance (longest simple path) between any two nodes.
 *
 * ALGORITHM (Two-BFS / Two-DFS Approach):
 * 1. Pick any arbitrary node (e.g. node 1) and run DFS/BFS to find the farthest node, let's call it 'u'.
 * 2. Run DFS/BFS from 'u' to find the farthest node from 'u', let's call it 'v'.
 * 3. The distance between 'u' and 'v' is the exact diameter of the tree!
 *
 * TIME COMPLEXITY: O(N) where N is number of nodes.
 * SPACE COMPLEXITY: O(N) for adjacency list and recursion stack.
 *
 * NOTE: Works for unweighted trees and trees with non-negative edge weights.
 */

const int MAXN = 2e5 + 5;
vector<pair<int, int>> adj[MAXN];
int farthest_node = -1;
long long max_dist = -1;

void dfs(int u, int p, long long d) {
    if (d > max_dist) {
        max_dist = d;
        farthest_node = u;
    }
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            dfs(v, u, d + w);
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w = 1; // Default weight 1 if unweighted
        cin >> u >> v;
        // If problem gives weights: cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step 1: Find the farthest node from node 1
    max_dist = -1;
    dfs(1, 0, 0);

    // Step 2: Find the farthest node from 'farthest_node'
    int start_node = farthest_node;
    max_dist = -1;
    dfs(start_node, 0, 0);

    cout << "Tree Diameter endpoints: " << start_node << " <---> " << farthest_node << "\n";
    cout << "Diameter Length: " << max_dist << "\n";
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

