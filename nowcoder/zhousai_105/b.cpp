#include <bits/stdc++.h>

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i) {
            int t = a[i] ^ a[i - 1];
            g = std::__gcd(t, g);
        }
    }
    std::cout << g << '\n';
    return 0;
}