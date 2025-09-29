#include <bits/stdc++.h>
const int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
           std::cin >>b[i];
        }
        std::vector<std::array<int, 2>> memo(n + 1, {-1, -1});
        auto dfs = [&](auto&& dfs, int u, int f) -> int {
            if (u == n) {
                return 1;
            }
            int res = memo[u][f];
            if (res != -1) {
                return res;
            }
            res = 0;
            if (u == 0) {
                res = (res + dfs(dfs, u + 1, 0)) % MOD;
                res = (res + dfs(dfs, u + 1, 1)) % MOD;
            } else {
                if (a[u] >= b[u - 1] && b[u] >= a[u - 1]) {
                    res = (res + dfs(dfs, u + 1, !f)) % MOD;
                }
                if (a[u] >= a[u - 1] && b[u] >= b[u - 1]) {
                    res = (res + dfs(dfs, u + 1, f)) % MOD;
                }
            }
            return res;
        };
        std::cout << dfs(dfs, 0, 0) << '\n';
    }
    return 0;
}