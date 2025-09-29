#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> vis(m + 1);
    for (int i = 0; i < m; i++) {
        int t = 1;
        for (int j = 1; j < n; j++) {
            if (a[j][i] != a[0][i]) {
                break;
            }
            t++;
        }
        vis[a[0][i]] = max(vis[a[0][i]], t);
    }
    int ans = n * m;
    for (int i = 1; i <= m; i++) {
        ans -= vis[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}