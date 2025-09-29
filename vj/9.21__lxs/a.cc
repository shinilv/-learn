#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, x, y;
        std::cin >> a >> b >> c >> x >> y;
        x = std::max(0, x - a);
        y = std::max(0, y - b);
        if (x + y <= c) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }
    return 0;
}