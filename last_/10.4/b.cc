#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, m;
    std::cin >> n >>m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end(), std::greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += m * a[i];
        m--;
        if (m == 0) break;
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