#include <bits/stdc++.h>
#define int long long

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int ans = std::min((a != 1) + (a != n) + (b != 1) + (b != m), 
                        (c != 1) + (c != n) + (d != 1) + (d != m));
        std::cout << ans << '\n';
    }
    return 0;
}