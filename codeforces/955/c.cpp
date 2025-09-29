#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    std::vector<int> dp(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] >= l && a[i] <= r) {
            dp[i] = dp[i - 1] + 1;
        } else if(a[i] < l) {
            int x = pre[i] - l;
            int p = upper_bound(pre.begin(), pre.begin() + i, x) - pre.begin();
            if (p == 0) {
                continue;
            }
            if (pre[i] - pre[p - 1] >= l && pre[i] - pre[p - 1] <= r) {
                dp[i] = std::max(dp[i], dp[p - 1] + 1);
            }
        }
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}