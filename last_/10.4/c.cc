#include <bits/stdc++.h>
#define int long long

void solve() {
    int k, x;
    std::cin >> k >> x;
    int t = 1LL << k;
    int y = t * 2 - x;
    std::vector<int> ans;
    while (x != y) {
        if (x < y) {
            y -= x;
            x *= 2;
            ans.push_back(1);
        } else {
            x -= y;
            y *= 2;\
            ans.push_back(2);
        }
    }
    std::cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        std::cout << ans[i] << " \n"[i == 0];
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