#include <bits/stdc++.h>
#define int long long

void solve() {
    int k, l1, r1, l2, r2;
    std::cin >> k >> l1 >> r1 >> l2 >> r2;
    int t = 1;
    int ans = 0;
    while (t <= r2 / l1) {
        // std::cout << t << '\n';
        int l = l1, r = r1;
        while (l < r) {
            int mid = l + r >> 1;
            if (mid * t >= l2) r = mid;
            else l = mid + 1;
        }
        int x = l;
        if (l * t < l2 || l * t > r2) {
            t *= k;
            continue;
        }
        l = l1, r = r1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (mid * t <= r2) l = mid;
            else r = mid - 1;
        }
        ans += (l - x + 1);
        t *= k;
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