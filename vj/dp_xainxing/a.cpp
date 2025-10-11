#include <bits/stdc++.h>

signed main() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n + 1);
    int f = 0;
    if (l > r) f = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    a[0] = -1;
    int m;
    std::cin >> m;
    int pos1 = l, pos2 = l;
    while (m--) {
        int x;
        std::cin >> x;
        // std::cout << pos1 << ' ' << pos2 << '\n';
        if (x == a[pos1 + 1] && pos1 < n) {
            pos1++;
        } else {
           if (!f) std::cout << "Wrong\n";
           else std::cout << "Right\n";
           return 0;
        }
        if (x == a[pos2 - 1] && pos2 > 1) {
            pos2--;
        } else {
            if (f) std::cout << "Wrong\n";
            else std::cout << "Right\n";
            return 0;
        }
    }
    std::cout << "Unsure\n";
    
    return 0;
}