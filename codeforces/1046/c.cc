#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> mp(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int x = a[i - 1];
        dp[i] = dp[i - 1];
        int p = lower_bound(mp[x].begin(), mp[x].end(), i - 1) - mp[x].begin();
        if (p + 1 >= x) {
            dp[i] = max(dp[i], dp[mp[x][p - x + 1]] + x);
        }
    }
    cout << dp[n] << '\n';

}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}