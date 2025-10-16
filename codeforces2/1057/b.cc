#include <bits/stdc++.h>
#define int long long

void solve() {
    int x, y, z;
    std::cin >> x >> y >> z;
    for (int i = 0; i < 30; i++) {
        int cnt = (x >> i & 1) + (y >> i & 1) + (z >> i & 1);
        if (cnt == 2) {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}