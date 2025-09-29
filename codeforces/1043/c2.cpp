#include <bits/stdc++.h>
#define int long long
int f[25], g[25];

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0;
    int cnt = 0;
    std::vector<std::array<int, 2>> vec;
    for (int i = 23; i >= 0; i--) {
        if (f[i] <= n) {
            ans += g[i] * (n / f[i]);
            cnt += n / f[i];
            vec.push_back({n / f[i], i});
            n -= (n / f[i]) * f[i];
        }
    }
    if (k < cnt) {
        std::cout << "-1\n";
        return;
    }
    int t = k - cnt;
    for (int i = 0; i < vec.size(); i++) {
        int nxt = (i + 1 < vec.size() ? vec[i + 1][1] : -1);
        int tt = vec[i][0], idx = vec[i][1];
        while (tt * 2 <= t && idx) {
            t -= tt * 2;
            ans -= tt * g[idx];
            tt *= 3; idx--;
            ans += tt * g[idx];
            if (idx == nxt) {      
                vec[i + 1][0] += tt;
                idx = 0;
                break;
            }
        }
        if (idx) {
            ans -= (t / 2) * g[idx];
            idx--;
            ans += (t / 2) * 3 * g[idx];
            break; 
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