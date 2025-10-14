#include <bits/stdc++.h>

signed main() {
    int n, m;
    std::cin >> n >> m;
    int g[11][11]{};
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    int ans = INT_MAX;
    for (int mask = 0; mask < 1 << n; mask++) {
        int vis[11]{};
        for (int j = 0; j < n; j++) {
            if (mask >> j & 1) vis[j] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j] && vis[i] == vis[j]) res++;
            }
        }
        ans = std::min(ans, res);
    }
    std::cout << ans << '\n';
    return 0;
}