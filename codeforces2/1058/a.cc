#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;  
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    for (int i = 0; ; i++) {
        if (!mp.count(i)) {
            std::cout << i << '\n';
            return;
        }
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