#include <bits/stdc++.h>
#define int long long

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if ((a - b) * (c - d) > 0) {
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
}