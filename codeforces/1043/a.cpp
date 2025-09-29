#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s, t, op;
    std::cin >> s;
    int m;
    std::cin >> m;
    std::cin >> t >> op;
    for (int i = 0; i < m; i++) {
        if (op[i] == 'V') {
            s = t[i] + s;
        } else {
            s += t[i];
        }
    }
    std::cout << s << '\n';
    
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}