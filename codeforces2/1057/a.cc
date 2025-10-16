#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    std::cout << mp.size() << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}