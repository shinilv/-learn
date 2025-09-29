#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[n - i - 1][n - j - 1]) {
                t++;
            }
        }
        if (i == n / 2) {
            ans += t / 2;
        } else {
            ans += t;
        }
    }
    if (ans > k || ((k - ans) & 1) && (n % 2 == 0)) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}