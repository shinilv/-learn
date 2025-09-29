#include <bits/stdc++.h>
#define int long long

struct pa {
    int t, x;
    bool operator<(const pa& w) const {
        if (w.t == t) {
            return x < w.x;
        }
        return t > w.t;
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> ans(n + 1), cnt(n + 1), f(n + 1);
    std::vector<std::set<pa>> se(n + 1);
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        // std::cout << u << '\n';
        ans[u] = a[u];
        cnt[u] = 1;
        for (auto x : g[u]) {
            if (x == fa) {
                continue;
            }
            dfs(dfs, x, u);
            f[x] = u;
            ans[u] += ans[x];
            cnt[u] += cnt[x];
            se[u].insert({cnt[x], x});
        }
    };
    dfs(dfs, 1, 0);
    while (m--) {
        int op;
        std::cin >> op;
        int x;
        std::cin >> x;
        if (op == 1) {
            std::cout << ans[x] << '\n';
        } else {
            if (se[x].empty()) {
                continue;
            }
            auto it = se[x].begin();
            int s =(*it).x;
            se[f[x]].erase({cnt[x], x});
            ans[x] -= ans[s];
            ans[s] += ans[x];
            cnt[x] -= cnt[s];
            cnt[s] += cnt[x];
            se[s].insert({cnt[x], x});
            se[f[x]].insert({cnt[s], s});
            se[x].erase(*it);
            int ff = f[x];
            f[x] = s;
            f[s] = ff;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}