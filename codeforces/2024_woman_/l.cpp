#include <bits/stdc++.h>
#define int long long

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a < 4) {
        std::cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i = 2; ; i++) {
        int j = 2;
        if ((i + j) * 2 - 8 > b + c) break;
        if (i * j - (i + j) * 2 + 4 > d) break;
        int k = (i + j) * 2 - 8;
        if (b < k / 2 || c < k / 2) {
            break;
        }
        for (j = 2; ; j++) {
            if ((i + j) * 2 - 8 > b + c) break;
            if (i * j - (i + j) * 2 + 4 > d) break;
            int k = (i + j) * 2 - 8;
            if (b < k / 2 || c < k / 2) {
                break;
            }
            ans = std::max(ans, i * j);
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}