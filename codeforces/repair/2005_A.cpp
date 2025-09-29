#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >>n;
    std::string s = "aeiou", ans;
    if (n < 5) {
        ans = s.substr(0, n);
    } else {
        int t = n / 5;
        int x = n % 5;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < t; j++) {
                ans += s[i];
            }
            if (x) ans += s[i], x--;
        }
    }
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