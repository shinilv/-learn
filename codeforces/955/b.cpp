#include <bits/stdc++.h>
#define int long long

void solve() {
    int x, y, k;
    std::cin >> x >> y >> k;
    int ans = x;
    while (k) {
        ans++, k--;
        int m = (y - ans % y) % y;
        if (k >= m) {
            k -= m;
            ans += m;
            while (ans % y == 0) {
                ans /= y;
            }
        } else {
            ans += k;
            k = 0;
        }
        if (ans == 1) {
            k = (k % (y - 1));
            ans += k;
            k = 0;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}