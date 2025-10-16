#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x == 0) ans++;
        else if (x == -1) cnt++;
    }
    std::cout << ans + (cnt & 1) * 2 << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}