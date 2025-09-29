#include <bits/stdc++.h>
#define int long long

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::unordered_map<double, int> mp;
    std::map<std::pair<double, int>, int> vis;
    int ans = 0, p = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        for (int j = 0; j < i; j++) {
            double x;
            if (b[i] == b[j]) {
                x = 1e9;
            } else {
                x = (double)(a[i] - a[j]) / (double)(b[i] - b[j]);
            }
            ans += mp[x];
            mp[x]++;
            int len = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
            p += vis[{x, len}];
            vis[{x, len}]++;
        }
    }
    std::cout << ans - p / 2 << '\n';
    return 0;
}