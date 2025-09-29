#include <bits/stdc++.h>
#define int long long

/*
思路：让我们从最小数中减去 n, 从第二个最小数中减去 n−1，从第三个 …中减去 n−2，再从最大数中减去  1
显然没有更好的结果
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    std::vector<int> ans(n + 1);
    int cnt = n;
    for (auto [k, idx] : a) {
        ans[idx] = cnt--; 
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << ' ';
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