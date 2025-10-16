#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    int cnt = 0, x = 0;
    std::set<int> se;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x < k) se.insert(x);
        else if (x == k) cnt++;
    }
    int ans = std::max(cnt, k - (int)se.size());
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