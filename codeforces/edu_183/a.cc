#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::cout << (3 - (n % 3)) % 3 << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}