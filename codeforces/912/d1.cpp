#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> aa(a);
    while (q--) {
        int k;
        std::cin >> k;
        int ans = 0;
        for (int j = 59; j >= 0; j--) {
            std::vector<int> b(n);
            int tmp = k, f = 0;
            for (int i = 0; i < n; i++) {
                int x = a[i];
                if (!(x >> j & 1)) {
                    int t = (1LL << j) - (((1LL << j) - 1) & x);
                    if (tmp < t) {
                        f = 1;
                        break;
                    }
                    tmp -= t;
                    b[i] = x + t;
                } else {
                    b[i] = x;
                }
            }
            if (!f) {
                a = b;
                ans += (1LL << j);
                k = tmp;
            }
        }
        std::cout << ans << '\n';
        a = aa;
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}