#include <bits/stdc++.h>
using namespace std;
#define int long long

void chmin(int& x, const int y) {
    if (x > y) {
        x = y;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<array<int, 3>> cnt1, cnt2;

    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
   
        for (auto [y, w] : g[u]) {
            if (y == fa) continue;
            cnt1.push_back({w, u, y});
            dfs(dfs, y, u);
            cnt2.push_back({w, y, u});
        }
    };
    dfs(dfs, 1, -1);

    vector<array<int, 2>> g1(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g1.push_back({u, v});
        g1.push_back({v, u});
    }

    vector<int> dp(n + 1, LLONG_MAX / 2);
    dp[1] = 0;
    for (int k = 0; k <= n; k++) {
        for (auto& [w, x, y] : cnt2) {
            chmin(dp[y], dp[x] + w);
        }
        for (auto& [w, x, y] : cnt1) {
            chmin(dp[y], dp[x] + w);
        }

        cout << accumulate(dp.begin() + 1, dp.end(), 0LL) << '\n';
        auto ndp = dp;
        for (auto [x, y] : g1) {
            chmin(ndp[y], dp[x]);
        }
        dp = ndp;
    }
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