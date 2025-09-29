#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::map<char, std::pair<int, int>> mp;
    mp['R'] = {0, 1};
    mp['L'] = {0, -1};
    mp['D'] = {1, 0};
    mp['U'] = {-1, 0};
    std::vector<std::vector<int>> memo(n, std::vector<int>(m, -1));

    auto dfs = [&](auto&& dfs, int x, int y) {
        
        int& res = memo[x][y];
        if (res != -1) {
            return res;
        }
        res = 1;
        if (a[x][y] != '?') {
            int k = a[x][y];
            int tx = x + mp[k].first, ty = y + mp[k].second;
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                return res = 0;
            } else {
                return res = dfs(dfs, tx, ty);
            }
        } else {
            int t = 0;
            for (auto& [k, p] : mp) {
                int tx = x + p.first, ty = y + p.second;
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                    continue;
                }
                if (a[tx][ty] == '?') {
                    t = 1;
                    break;
                }
                t |= dfs(dfs, tx, ty);
            }
            return res = t;
        }

    }; 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += dfs(dfs, i, j);
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}