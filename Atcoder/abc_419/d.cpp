#include <bits/stdc++.h>
#define int long long

signed main() {
    int n, q;
    std::cin >> n >> q;
    std::string s, t;
    std::cin >> s >> t;
    s = ' ' + s, t = ' ' + t; 
    std::vector<int> f(n + 2);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        f[l]++;
        f[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] & 1) {
            std::cout << t[i];
        } else {
            std::cout << s[i];
        }
    }
    std::cout << '\n';

    return 0;
} 