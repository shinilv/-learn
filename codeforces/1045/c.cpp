#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        if (i + 1 <= n - 1) {
            int x = a[i - 1] + a[i + 1];
            if (a[i] < x) {
                ans += x - a[i];
                a[i + 1] = std::max(0LL, a[i + 1] - (x - a[i]));
            }
        } else {
            ans += std::max(0LL, a[i - 1] - a[i]);
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}