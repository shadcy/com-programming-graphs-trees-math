#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
 * PROBLEM: Multi-Source BFS on 2D Grids
 * (Classic Pattern: Rotting Oranges, Distance to Nearest 0, Shortest Bridge)
 *
 * KEY IDEA:
 * Instead of running separate BFS from each source (which causes O((R * C)^2) TLE),
 * initialize the BFS queue with ALL source coordinates simultaneously at time = 0.
 * The BFS explores outward in concentric wave-fronts, computing the shortest distance
 * from ANY source to every cell in linear time O(R * C)!
 *
 * TIME COMPLEXITY: O(Rows * Cols)
 * SPACE COMPLEXITY: O(Rows * Cols)
 */

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve() {
    int rows, cols;
    if (!(cin >> rows >> cols)) return;

    vector<vector<int>> grid(rows, vector<int>(cols));
    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;

    // Read grid:
    // 1 = Source (e.g. rotten orange / fire / starting cell)
    // 0 = Target cell
    // -1 = Wall / Obstacle
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 1) {
                // Multi-source entry point!
                dist[r][c] = 0;
                q.push({r, c});
            }
        }
    }

    int max_time = 0;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        max_time = max(max_time, dist[r][c]);

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            // Check boundary and unvisited condition
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (grid[nr][nc] != -1 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << "Distance Matrix from Nearest Source:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(3) << dist[r][c] << " ";
        }
        cout << "\n";
    }

    cout << "\nMax Time to reach all accessible cells: " << max_time << "\n";
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

