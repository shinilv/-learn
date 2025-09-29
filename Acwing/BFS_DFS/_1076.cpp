#include <bits/stdc++.h>
#define int long long 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

signed main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    
    std::queue<std::array<int, 2>> q;
    q.push({0, 0});
    std::vector<std::vector<int>> vis(n, std::vector<int>(n));
    std::vector<std::vector<std::array<int, 2>>> pre(n, std::vector<std::array<int, 2>>(n, {-1, -1}));
    vis[0][0] = 1;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && a[tx][ty] == 0 && !vis[tx][ty]) {
                q.push({tx, ty});
                pre[tx][ty] = {x, y};
                vis[tx][ty] = 1;
                if (tx == n - 1 && ty == n - 1) {
                    std::vector<std::array<int, 2>> ans;
                    ans.push_back({tx, ty});
                    std::array<int, 2> tt({-1, -1});
                    while (pre[tx][ty] != tt) {
                        ans.push_back(pre[tx][ty]);
                        auto [t1, t2] = pre[tx][ty];
                        tx = t1, ty = t2;
                    }
                    std::reverse(ans.begin(), ans.end());
                    for (auto [t1, t2] : ans) {
                        std::cout << t1 << ' ' << t2 << '\n';
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}