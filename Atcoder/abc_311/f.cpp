#include <bits/stdc++.h>
const int MOD = 998244353;

/*
思路： 定义 dp[i][j]表示前i列，其中第i列的情况是，j 行及以下都是黑色，以上都是白色 的方案数。
详细见题解：https://www.cnblogs.com/Lanly/p/17574427.html
*/

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                if (i < n - 1) {
                    a[i + 1][j] = '#';
                    if (j < m - 1) {
                        a[i + 1][j + 1] = '#';
                    }
                }
            }
        }
    }
    std::vector<int> dp(n + 1, 0);
    // 初始化 第 -1 列全为白色这一种方案
    dp[n] = 1;
    for (int i = 0; i < m; i++) {
        std::vector<int> dp2(n + 1, 0);
        int sufsum = 0;
        for (int j = n; j >= 0; j--) {
            sufsum = (sufsum + dp[j]) % MOD;
            if (j > 0 && a[j - 1][i] == '#') {
                continue;
            }
            if (j > 0) {
                dp2[j] = dp[j - 1] + sufsum;
            } else {
                dp2[j] = sufsum;
            }
            dp2[j] %= MOD;
        }
        dp = dp2;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    std::cout << ans << '\n';
    return 0;
}