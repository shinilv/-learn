#include <bits/stdc++.h>
#define int long long
int p[200010];
int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int k, x;
        std::cin >> k;
        while (k--) {
            std::cin >> x;
            g[i].push_back(x);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = n; i >= 1; i--) {
        if (g[i].empty()) continue;
        for (auto x : g[i]) {
            std::cout << i << ' ' <<  find(x) << '\n';
            p[find(x)] = i;
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