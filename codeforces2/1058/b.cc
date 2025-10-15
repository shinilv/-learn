#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n ;i++) {
        std::cin >> b[i];
    }
    int cnt = 1;
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int x = b[i] - b[i - 1];
        if (x <= ans.size()) {
            ans.push_back(ans[ans.size() - x]);
        } else {
            ans.push_back(cnt++);
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}