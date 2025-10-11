#include <bits/stdc++.h>

void solve() {
    int a, b;
    std::cin >> a >> b;
    int ans = 0;
    if (a == b) {
        ans = 0;
    } else if (a % b == 0 || b % a == 0) {
        ans = 1;
    } else {
        ans = 2;
    }
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}