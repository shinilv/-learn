#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::string ans;
    if (n == m) {
        for (int i = 0; i < n; i++) ans += '-';
    } else {
        int cnt0 = 0, cnt1 = 0, cnt = 0;
        for (auto x : s) {
            if (x == '0') cnt0++;
            else if (x == '1') cnt1++;
            else cnt++;
        }
        for (int i = 0; i < cnt0; i++) ans += '-';
        if (n - cnt0 - cnt1 > cnt * 2) {
            for (int i = 0; i < cnt; i++) ans += '?';
            for (int i = 0; i < n - cnt0 - cnt1 - cnt * 2; i++) ans += '+';
            for (int i = 0; i < cnt; i++) ans += '?';
        }else {
            for (int i = 0; i < n - cnt0 - cnt1; i++) ans += '?';
        }
        for (int i = 0; i < cnt1; i++) ans += '-';
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