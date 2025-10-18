#include <bits/stdc++.h>
#define int long long

int func(int a) {
    int res = 0;
    while (a) {
        a >>= 1;
        res++;
    }
    return res;
}

void solve() {
    int a, b;
    std::cin >> a >> b;
    int len1 = 0, len2 = 0;
    int x = a, y = b;
    len1 = func(a), len2 = func(b);
    if (len2 > len1) {
        std::cout << "-1\n";
    }else {
        std::vector<int> ans;
        for (int i = 0; i < 30; i++) {
            if ((a >> i & 1) != (b >> i & 1)) {
                ans.push_back(1 << i);
            }
        }
        std::cout << ans.size() << '\n';
        int p = a;
        for (auto x : ans) {
            assert(x <= p);
            std::cout << x << ' ';
            p ^= x;
        }
        assert(b == p);
        std::cout << '\n';
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