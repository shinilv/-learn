#include <bits/stdc++.h>
#define int long long
const int MOD = 998244353;

int qui(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return r;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> a(m), b(m);
    int t = 0;

    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
        int x = v[a[i]] ^ v[b[i]];
        g[a[i]].push_back(x);
        g[b[i]].push_back(x);
        t = (t + v[a[i]] + v[b[i]]) % MOD;
    }

    std::vector<std::vector<int>> bc(n + 1, std::vector<int>(60, 0));
    for (int u = 1; u <= n; u++) {
        for (int y : g[u]) {
            for (int k = 0; k < 60; k++) {
                if (y >> k & 1) bc[u][k]++;
            }
        }
    }

    auto calc = [&](int u, int X) -> int {
        int s = 0, d = g[u].size();
        for (int k = 0; k < 60; k++) {
            int c = bc[u][k];
            int p = 1LL << k;
            int o = (X >> k & 1) ? (d - c) : c;
            s = (s + p % MOD * o) % MOD;
        }
        return s;
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans + calc(a[i], v[b[i]])) % MOD;
        ans = (ans + calc(b[i], v[a[i]])) % MOD;
    }

    ans = (ans - t + MOD) % MOD;
    ans = ans * qui(2, MOD - 2) % MOD;
    std::cout << ans << '\n';

    return 0;
}
