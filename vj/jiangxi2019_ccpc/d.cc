#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[101][101];

signed main() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            dp[a[i]][j] = dp[j][a[i]] + 1;
            ans = max(ans, dp[a[i]][j]);
        }
    }
    cout << ans << '\n';


    return 0;
}