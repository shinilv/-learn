#include <bits/stdc++.h>
#define int long long
int f[25], g[25];
 
void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 23; i >= 0; i--) {
        if (f[i] <= n) {
            ans += g[i] * (n / f[i]);
            n -= (n / f[i]) * f[i];
        }
    }
    std::cout << ans << '\n';
}
 
signed main() {
    f[0] = 1;
    for (int i = 1; i < 25; i++) {
        f[i] = f[i - 1] * 3;
    }
    g[0] = 3;
    for (int i = 1; i < 24; i++) {
        g[i] = f[i + 1] + i * f[i - 1];
    }
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}