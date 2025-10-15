#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> s(std::min(n, m), std::vector<char>(std::max(n, m)));
    int f = n > m;
    getchar();
    if (f) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                std::cin >> s[i][j];
            }
            getchar();
        }
        std::swap(n, m);
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> s[i][j];
            }
            getchar();
        }
    }
    std::vector<std::array<int, 5>> vec;
    
    for (int u = 0; u < n; u++) {
        std::set<long long> se;
        for (int d = u + 1; d < n; d++) {
            int list = -1;
            for (int i = 0; i < m; i++) {
                if (s[u][i] == '1' && s[d][i] == '1') {
                    if (list != -1 && !se.count((long long)list * m + i)) {
                        se.insert((long long)m * list + i); // 贪心去重
                        int v = (d - u + 1) * (i - list + 1);
                        vec.push_back({v, u, d, list, i});
                    }
                    list = i;
                }
            }
        }
    }
    sort(vec.begin(), vec.end());
    std::vector<std::set<int>> se(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            se[i].insert(j);
        }
    }
    std::vector<std::vector<int>> ans(n, std::vector<int>(m));
    for (auto& [v, u, d, l, r] : vec) {
        // std::cout << v << '\n';
        for (int h = u; h <= d; h++) {
            auto it = se[h].lower_bound(l);
            while (*it <= r) {
                ans[h][*it] = v;
                it = se[h].erase(it);
            }
        }
    }
    // std::cout << ans[0][0] << '\n';
    if (f) {
        std::swap(n, m);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                std::cout << ans[i][j] << ' ';
            }
            std::cout << '\n';
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << ans[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    std::cout << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}