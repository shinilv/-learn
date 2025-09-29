#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int d = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (i > d) {
            std::cout << 0 << '\n';
            return;
        }
        ans = (ans * (d - i)) % MOD;
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