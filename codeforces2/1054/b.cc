#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    sort(a.begin(), a.end());
     int ans = 0;
     for (int i = 0; i < n; i += 2) {
        ans = std::max(ans, a[i + 1] - a[i]);
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