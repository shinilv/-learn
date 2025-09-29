#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    if (a == b || k > 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
