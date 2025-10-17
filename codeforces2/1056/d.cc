#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    for (int d = 1; ; d++) {
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << ' ' << (i + d) % n + 1 << std::endl;
            int x;
            std::cin >> x;
            if (x) {
                return;
            }
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}