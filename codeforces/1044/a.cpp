#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (mp.count(x)) {
            ans = 1;
        }
        mp[x]++;
    }
    if (ans) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
