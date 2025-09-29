#include <bits/stdc++.h>
#define int long long

signed main() {
    int n;
    std::cin >> n;
    int a = INT_MIN, b = INT_MAX, c = INT_MIN, d = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        a = std::max(x, a);
        b = std::min(b, x);
        c = std::max(c, y);
        d = std::min(d, y);
    }
    // std::cout << a << ' ' << b << '\n';
    int ans = std::max((c - d + 1) / 2, (a - b + 1) / 2);
    std::cout << ans << '\n';
    return 0;
} 