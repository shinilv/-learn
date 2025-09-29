#include <bits/stdc++.h>
#define int long long

int query(int x, int y) {
    std::cout << "? " << x << ' ' << y << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    int t = query(1, 1) + 1;
    if (t > n) {
        int x = query(1, t) + 1;
        std::cout << "! " << x <<  ' ' << t << std::endl;
    } else if (t > m) {
        int y = query(t, 1) + 1;
        std::cout << "! " << t <<  ' ' << y << std::endl;
    } else {
        int p = query(t, t);
        int x = t, y = t - p;
        if (query(x, y) == 0) {
            std::cout << "! " << x << ' ' << y << std::endl; 
        } else {
            std::cout << "! " << y << ' ' << x << std::endl; 
        }
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