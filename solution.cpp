#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << "\n";
#else
#define debug(x)
#endif

// Example OA Problem: Maximum Subarray Sum (Kadane's Algorithm)
void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max_so_far = a[0];
    ll current_max = a[0];

    for (int i = 1; i < n; i++) {
        current_max = max(a[i], current_max + a[i]);
        max_so_far = max(max_so_far, current_max);
    }

    debug(n);
    debug(max_so_far);

    cout << max_so_far << "\n";
}

int main() {
    FAST_IO;

    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}

