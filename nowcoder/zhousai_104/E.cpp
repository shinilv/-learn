#include <bits/stdc++.h>
#define int long long

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        idx[a[i]] = i;
    }
    int ans = 0;
    int l = idx[1], r = idx[1];
    for (int i = 1; i <= n; i++) {
        r = std::max(idx[i], r);
        l = std::min(idx[i], l);
        ans += l * (n - r + 1);
    }
    std::cout << ans << '\n';
    return 0;
} 