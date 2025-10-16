#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnta = 0, cntb = 0;
    for (auto x : s) {
        if (x == 'a') cnta++;
        else cntb++;
    }

    auto check = [&](char ch) -> int {
        int cnt = 0;
        int res = 0;
        std::vector<int> t(n);
        for (int i = 0; i < n; i++) {
            if (s[i] != ch) cnt++;
            else {
                t[i] = cnt;
            }
        }
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ch) cnt++;
            else {
                t[i] = std::min(t[i], cnt);
                res += t[i];
            }
        }
        return res;
    };

    int ans = std::min(check('a'), check('b'));
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