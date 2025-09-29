#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        g = std::__gcd(g, abs(a[i] - i));
    }
    std::cout << g << '\n';
}



signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}