#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> ans(60, -1);
    auto dfs = [&](auto&& dfs, int mask, int l, int r) -> bool {
        if (mask < 0) {
            return 1;
        }
        int f = -1;
        for (int i = l + 1; i <= r; i++) {
            if ((a[i] >> mask & 1) != (a[i - 1] >> mask & 1)) {
                f = i;
                if (a[i] >> mask & 1) {
                    if (ans[mask] != -1 && ans[mask]) return 0;
                    ans[mask] = 0;
                } else {
                    if (ans[mask] != -1 && ans[mask] == 0) return 0;
                    ans[mask] = 1;
                }
            }
        }
        if (f == -1) {
            return dfs(dfs, mask - 1, l, r);
        }
        return dfs(dfs, mask - 1, l, f - 1) && dfs(dfs, mask - 1, f, r);
    };

    if (!dfs(dfs, 59, 0, n - 1)) {
        std::cout << "0\n";
        return;
    }

    std::vector<int> res;
    int sum = 0;

    for (int i = 0; i < 60; i++) {
        if (ans[i] == 1) {
            k -= (1LL << i);
        } else if (ans[i] == -1) {
            res.push_back(1LL << i);
            sum += (1LL << i);
        }
    }
    if (k < 0) {
        std::cout << "0\n";
        return;
    }

    int len = res.size() - 1;
    auto re = [&](auto&& re, int u, int x, int su) -> int {
        if (u < 0) {
            return 1;
        }
        if (x >= su) {
            return 1LL << (u + 1);
        }
        int r = re(re, u - 1, x, su - res[u]);
        if (x >= res[u]) {
            r += re(re, u - 1, x - res[u], su - res[u]);
        }
        return r;
    };
    std::cout << re(re, len, k, sum) << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}