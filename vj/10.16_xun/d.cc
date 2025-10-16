#include <bits/stdc++.h>
#define int long long

signed main() {
    int n, m;
    std::cin >> n >> m;
    int t = 1;
    std::vector<int> cnt(n + 1, 1);
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        int ans = 0;
        while (t <= a) {
            cnt[b] += cnt[t];
            ans += cnt[t];
            cnt[t] = 0;
            t++;
        }
        std::cout << ans << '\n';
    }
    return 0;
}