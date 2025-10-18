#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        cnt[a[i]]++;
    }
    std::vector<int> ans, vis(n + 1);
    for (int i = 1; i <= n ;i++) {
        if (cnt[i] == 0) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0) {
        for (int i = 0; i < k; i++) {
            std::cout << a[i] << ' ';
        }
    } else if (ans.size() == 1) {
        std::cout << ans[0] << ' ';
        int p = 1;
        if (ans[0] == 1) p = 2;
        for (int i = 1; i <= n; i++) {
            if (i != a[n - 1] && i != ans[0]) {
                p = i;
                break;
            }
        }
        if (k > 1) {
            std::cout << p << ' ';
        }
        for (int i = 1, j = 0; i <= n, j < k - 2; i++) {
            if (i == ans[0] || i == p) continue;
            std::cout << i << ' ';
            j++;
        }
    } else {
        if (k == 1) {
            std::cout << ans[0] << '\n';
            return;
        }
        std::cout << ans[0] << ' ' << ans[1] << ' ';
        for (int i = 1, j = 0; i <= n && j < k - 2; i++) {
            if (i == ans[0] || i == ans[1]) continue;
            std::cout << i << ' ';
            j++;
        }
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