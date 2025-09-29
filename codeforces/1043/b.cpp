#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> ans;
    int t = 10;
    while (t < n) {
        if (n % (t + 1) == 0) {
            ans.push_back(n / (t + 1));
        }
        t *= 10;
    }
    sort(ans.begin(), ans.end());
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