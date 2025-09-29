#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int t = a[i] % (k + 1);
        a[i] = a[i] + t * k;
    }
    for (auto x : a) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}