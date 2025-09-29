#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(x + 1, INT_MIN)), dp2(m + 1, vector<int>(x + 1, INT_MIN));
    for (int i = 0; i <= m; i++) {
        dp2[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= x; k++) {
                if (a[i][j] != '?') {
                    int v = a[i][j] - '0';
                    dp[j][k] = max(dp[j - 1][k], dp2[j][k]) + v;
                } else {
                    if (k) {
                        dp[j][k] = max(dp2[j][k - 1], dp[j - 1][k - 1]) + 1;
                        dp[j][k] = max({dp[j][k], dp2[j][k], dp[j - 1][k]});
                    } else {
                        dp[j][k] = max(dp2[j][k], dp[j - 1][k]);
                    }
                }
            }
        }
        dp.swap(dp2);
    }
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        ans = max(ans, dp2[m][i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}