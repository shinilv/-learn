#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    dp[0] = a[0];
    if (n > 1) {
        dp[1] = dp[0] + a[1] - 1;
    }
    for (int i = 2; i < n; i++) {
        dp[i] = std::min(dp[i - 1] + a[i] - 1, dp[i - 2] + a[i - 1] + std::max(0LL, a[i] - i));
    }
    std::cout << dp.back() << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
