#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> p(n + 1, -1), path;
    vector<vector<int>> cycs;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs = [&](auto&& dfs, int u) -> void {
        vis[u] = true;
        path.push_back(u);

        for (int v : g[u]) {
            if (v == p[u]) continue;

            if (vis[v]) {
                vector<int> cyc;
                auto it = find(path.begin(), path.end(), v);
                for (; it != path.end(); ++it) cyc.push_back(*it);
                cycs.push_back(cyc);
            } else {
                p[v] = u;
                dfs(dfs, v);
            }
        }

        vis[u] = false;
        path.pop_back();
    };
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(dfs, i);
    }
    vector<int> st(n + 1);
    for (const auto& idx : cycs) {
        vector<int> cyc;
        for (auto x : idx) cyc.push_back(a[x]), st[x]++;
        int cnt = cyc.size();
        sort(cyc.begin(), cyc.end());
        if (cyc.back() == -1 && cnt % 2 == 0) {
            ans = ans * v % MOD;
        } else {
            for (int i = 0; i < cnt; i++) {
                if (cyc[i] != -1) {
                    if (cyc[i] != cyc.back()) {
                        cout << "0\n";
                        return;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            if (a[i] == -1) {
                ans = (ans * v) % MOD;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
