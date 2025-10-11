#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    int res = (n * (n + 1)) / 2 - k;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(res + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= res; j++) {
            for (int k = 1; k <= i; k++) {
                int now = k * (k + 1) / 2;
                if (now <= j && dp[i - k][j - now]) {
                    dp[i][j] = k;
                }
            }
        }
    }
    if (!dp[n][res]) {
        std::cout << "0\n";
        return;
    }
    std::vector<int> ans;
    int cur = n;
    while (cur) {
        int len = dp[cur][res];
        for (int i = cur - len + 1; i <= cur; i++) {
            std::cout << i << ' ';
        }
        cur -= len;
        res -= len * (len + 1) / 2;
    }
    std::cout << '\n';

}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}