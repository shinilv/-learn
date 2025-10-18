#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> pre(n + 1), pr(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        std::vector<int> pos;
        int cnt = 0;
        while (x) {
            if (x & 1) pos.push_back(cnt);
            cnt++;
            x >>= 1;
        }
        pre[i] = pre[i - 1] + cnt - 1;
        pr[i] = pr[i - 1];
        if (pos.size() > 2) pre[i]++;
        else if (pos.size() == 2) {
            if (pos[0] == 0) {
                pr[i]++;
            } else {
                pre[i]++;
            }
        }
    }
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        int ans = 0;
        ans = pre[r] - pre[l - 1];
        ans += (pr[r] - pr[l - 1]) / 2;
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}