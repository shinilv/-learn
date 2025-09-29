#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), dp(n + 1);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = std::max(dp[i + 1] + a[i], dp[i + 1] + cnt + a[i]);
        cnt += a[i];
    }
    std::cout << dp[0] << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}