#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string ans;
    while (n) {
        if (n & 1) ans += '1';
        else ans += '0';
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() && ans.back() == '0') {
        ans.pop_back();
    }
    std::string t = ans;
    reverse(ans.begin(), ans.end());
    if (t == ans && (ans.size() % 2 == 0 || ans[ans.size() / 2] == '0')) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}