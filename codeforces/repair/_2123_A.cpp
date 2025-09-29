#include <bits/stdc++.h>
#define int long long

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 4 == 0) {
            std::cout << "Bob\n";
        } else {
            std::cout << "Alice\n";
        }
    }
    return 0;
} 