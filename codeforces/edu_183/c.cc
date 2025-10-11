#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + ((s[i] == 'b') ? 1 : -1);
    }
    if (pre[n] == 0) {
        std::cout << "0\n";
        return;
    }
    int ans = n + 1;
    std::map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (mp.count(pre[i] - pre[n])) {
            ans = std::min(ans, i - mp[pre[i] - pre[n]]);
        }
        mp[pre[i]] = i;
    }
    if (ans == n) {
        ans = -1;
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}