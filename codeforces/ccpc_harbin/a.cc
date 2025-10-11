#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int f = 0, ans = 0;
    for (auto x : a) {
        char ch;
        ans += x;
        if (ans == 0) {
            if (f == 0) ch = '0';
            else if (f == 1) ch = '+';
            else ch = '-';
        } else {
            if (ans > 0) ch = '+';
            else ch = '-';
        }
        if (ans & 1) {
            if (ans > 0) f = 1;
            else f = -1;
        }
        std::cout << ch;
        ans /= 2;
    }
    std::cout << '\n';
}

signed main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}