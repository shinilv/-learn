#include <bits/stdc++.h>
std::vector<int> f[55];

void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> ans;
    bool ok = false;
    auto dfs = [&](auto&& dfs, int t, int up, int u) -> void {
        if (ok || (n - u) > t) {
            return;
        }
        if (n - u == t) {
            for (auto& x : ans) {
                std::cout << x << ' ';
            }
            for (int i = 0; i < n - u; i++) {
                std::cout << "1 ";
            }
            std::cout << '\n';
            ok = true; 
            return;
        }
        if (u == n) {
            return;
        }
        for (auto i : f[up]) {
            ans.push_back(i);
            dfs(dfs, t - i, i, u + 1);
            ans.pop_back();
        }
    };
    for (int i = m; i >= 1; i--) {
        if (i * n < x) {
            break;
        }
        dfs(dfs, x, i, 0);
        if (ok) break;
    }
    if (ok == false) {
        std::cout << "-1\n";
    }
} 

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    for (int i = 1; i <= 50; i++) {
        int cnt = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                f[i].push_back(j);
                if (i / j != j) f[i].push_back(i / j);
            }
        }
        sort(f[i].begin(), f[i].end());
    }
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}