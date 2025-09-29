#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        std::vector<int> cnt(30);
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
            if (i == j) continue;
            for (int k = 0; k < 30; k++) {
                if (a[i][j] >> k & 1) {
                    cnt[k]++;
                    if (cnt[k] == n - 1) {
                        ans[i] |= (1 << k);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && (ans[i] | ans[j]) != a[i][j]) {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
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
