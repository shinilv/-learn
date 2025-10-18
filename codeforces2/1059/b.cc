#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans.push_back(i + 1);
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}