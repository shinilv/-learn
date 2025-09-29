#include <bits/stdc++.h>
const int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> cnt(n + 1), ans(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        if (x < y) g[u].push_back(v), cnt[v]++;
        else g[v].push_back(u), cnt[u]++;
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }
    int p = 1;
    while (q.size()) {
        auto t = q.front(); q.pop();
        ans[t] = p++;
        for (auto x : g[t]) {
            if (--cnt[x] == 0) {
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}