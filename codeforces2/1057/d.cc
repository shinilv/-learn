#include <bits/stdc++.h>
#define int long long

int check(std::vector<int>& a) {
    int n = a.size();
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i + 1] = dp[i - 1] + abs(a[i] - a[i - 1]);
        if (i > 1) {
            int t = a[i] + a[i - 1] + a[i - 2] - std::max({a[i], a[i - 1], a[i - 2]}) - std::min({a[i], a[i - 1], a[i - 2]});
            dp[i + 1] = std::min(dp[i + 1], dp[i - 2] + abs(a[i] - t) + abs(a[i - 1] - t) + abs(a[i - 2] - t));
        }
    }
    return dp[n];
}

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i) b[i - 1] = a[i];
        if (i > 1) c[i - 2] = a[i];
    }
    b[n - 1] = a[0];
    c[n - 2] = a[0];
    c[n - 1] = a[1];

    ans = std::min({check(a), check(b), check(c)});
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}