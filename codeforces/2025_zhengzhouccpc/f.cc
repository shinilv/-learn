#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    vector<vector<int>> vis(n, vector<int>(m));
    queue<array<int, 2>> q;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    int f = 0, cnt = 1;
    
    auto dfs = [&](auto&& dfs, int x, int y) -> void {
        // cout << x << ' ' << y << '\n';
        vis[x][y] = cnt;
        if (f) q.push({x, y}), dis[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && a[tx][ty] == '.') {
                dfs(dfs, tx, ty);
            }
        }
    };
    dfs(dfs, 0, 0);
    if (vis[n - 1][m - 1]) {
        cout << 0 << '\n';
        return;
    }
    f = 1;
    cnt++;
    dfs(dfs, n - 1, m - 1);
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                if (vis[tx][ty] == 1) {
                    cout << dis[x][y] << '\n';
                    return;
                } 
                if (dis[tx][ty] == -1) {
                    dis[tx][ty] = dis[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >>  t;
    while (t--) solve();
    return 0;
}