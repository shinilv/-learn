#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mx = std::max(mx, x);
    }
    std::cout << mx << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}