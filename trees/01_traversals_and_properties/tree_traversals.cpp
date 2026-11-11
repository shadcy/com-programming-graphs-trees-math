#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * Tree Traversals & Core Properties:
 * 1. DFS (Depth-First Search): Subtree sizes, Depths, Heights
 * 2. BFS (Breadth-First Search / Level-Order)
 * 3. Preorder, Inorder, Postorder
 */

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int depth_arr[MAXN], height_arr[MAXN], subtree_sz[MAXN];

// DFS to compute depth, subtree size, and height
void dfs(int u, int p, int d) {
    depth_arr[u] = d;
    subtree_sz[u] = 1;
    height_arr[u] = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            subtree_sz[u] += subtree_sz[v];
            height_arr[u] = max(height_arr[u], height_arr[v] + 1);
        }
    }
}

// Level-Order Traversal (BFS)
void bfs(int root, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[root] = 0;
    q.push(root);

    cout << "BFS Level-Order: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    for (int i = 1; i <= n; i++) adj[i].clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    bfs(1, n);

    cout << "\nNode Stats (Rooted at 1):\n";
    cout << "Node | Depth | Height | Subtree Size\n";
    cout << "-------------------------------------\n";
    for (int i = 1; i <= n; i++) {
        cout << setw(4) << i << " | "
             << setw(5) << depth_arr[i] << " | "
             << setw(6) << height_arr[i] << " | "
             << setw(12) << subtree_sz[i] << "\n";
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

