#include <bits/stdc++.h>

signed main() {
    int n, k;
    std::cin >> n >> k;
    if (k & 1) {
        std::cout << "-1\n";
        return 0;
    }
    std::string t(n, '0');
    for (int i = 0; i < n; i++) {
        if (k) t[i] = '1';
        std::cout << t << '\n';
        if (k) t[i] = '0', k -= 2;
    }
    return 0;
}