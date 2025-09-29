#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    bool ok = false;
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        for (auto [x, w] : g[u]) {
            if (x == fa) {
                continue;
            }
            ans[x] = w - ans[u];
            if (ans[x] <= 0) {
                ok = true;
            }
            dfs(dfs, x, u);
        }
    };
    dfs(dfs, 1, 0);
    int mi = INT_MAX;
    for (int i = 1; i <= n; i++) {
        mi = min(mi, ans[i]);
    }
    if (mi <= 0) {
        ans[1] += 1 - mi;
        dfs(dfs, 1, 0);
        for (int i = 1; i <= n; i++) {
            if (ans[i] <= 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n";
    return 0;
}