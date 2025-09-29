#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if (b > a) {
        if ((n & 1) == (b & 1)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    } else {
        if ((n & 1) == (b & 1) && (n & 1) == (a & 1)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
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