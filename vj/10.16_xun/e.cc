#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt[2]{};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    if (!cnt[0] || !cnt[1]) {
        std::cout << "0\n";
        return;
    }
    
    auto check = [&](int t) -> int {
        int len = 1, x = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1] && (s[i] - '0') == t) {
                len++;
            } else {
                if (len) {
                    x = std::max(x, len);
                    len = 1;
                }
            }
        }
        if (len) x = std::max(x, len);
        return (cnt[t] - x) * 2 + cnt[!t];
    };

    int ans = std::min(check(0), check(1));
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