#include <bits/stdc++.h>
int p[510][510];
int memo[510][510];

signed main() {
    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<int> a(n);
    std::vector<std::vector<int>> b(l);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i % l].push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            int sum = 0;
            for (auto x : b[j]) {
                if (x <= i) {
                    sum += i - x;
                } else {
                    sum += m + i - x;
                }
            }
            p[j][i] = sum;
        }
    }
    memset(memo, -1, sizeof(memo));
    auto dfs = [&](auto&& dfs, int u, int s) -> int {
        if (u == l) {
            if (s == 0) {
                return 0;
            } else {
                return (n / l) * (m - s);
            }
        }
        int& res = memo[u][s];
        if (res != -1) {
            return res;
        }
        res = INT_MAX;
        for (int i = 0; i < m; i++) {
            res = std::min(res, dfs(dfs, u + 1, (s + i) % m) + p[u][i]);
        }
        return res;
    };
    int ans = dfs(dfs, 0, 0);
    std::cout << ans << '\n';
    return 0;
} 