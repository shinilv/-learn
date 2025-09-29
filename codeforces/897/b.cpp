#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    // 记录有多少对不同
    int cnt = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            cnt++;
        } 
    }
    std::string ans(n + 1, '0');
    for (int i = cnt; i <= n - cnt; i += 1 + (n % 2 == 0)) {
        ans[i] = '1';
    }
    std::cout << ans << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}