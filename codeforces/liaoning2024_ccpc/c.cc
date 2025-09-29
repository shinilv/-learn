#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<array<int, 2>> a(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(i);
        cnt[u]++;
        a[i] = {u, v};
    }
    vector<int> p, su(n + 1), t;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]) {
            p.push_back(a[i][1]);
        } else {
            su[i] = a[i][1];
        }
    }
    auto dfs = [&](auto&& dfs, int u) -> void {
        if (cnt[u] == 0) {
            return;
        }
        for (auto x : g[u]) {
            dfs(dfs, x);
            su[u] += su[x];
        }
        t.push_back(su[u]);
    };
    dfs(dfs, 0);
    p.push_back(2200);
    sort(p.begin(), p.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++) {
        if (t[i] > p[i] || t[i] > 2200) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}