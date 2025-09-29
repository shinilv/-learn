#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    int t = (n * (n + 1)) / 2;
    int x = (n - (t % n)) % n;
    std::cout << 1 + x << ' ';
    for (int i = 2; i <= n; i++) {
        std::cout << i << ' ';
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