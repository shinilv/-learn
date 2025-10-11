#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (k == 1) {
        std::cout << std::max(a[0] + *std::max_element(a.begin() + 1, a.end()), 
                        a.back() + *std::max_element(a.begin(), a.end() - 1)) << '\n';
        return;
    }
    sort(a.begin(), a.end(), std::greater<int>());
    int ans = 0;
    for (int i = 0; i < k + 1; i++) {
        ans += a[i];
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    } 
    return 0;
}