#include <bits/stdc++.h>
int n, m;
const int MAX = 210;
std::string a[MAX];
int vis[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    vis[x][y] = 1;
    // 选择四个方向
    for (int i = 0; i < 4; i++) {
        int tx = x, ty = y;
        while (a[tx + dx[i]][ty + dy[i]] != '#') {
            vis[tx][ty] = 1;
            tx += dx[i], ty += dy[i];
        }
        // 此时走到 a[tx][ty]，重新选择方向
        // 如果这个格子被走过的话就 一定不用重新遍历了
        if (!vis[tx][ty]) {
            dfs(tx, ty);
        } 
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    } 

    dfs(1, 1);

    int ans = 0;
    // 记录答案
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) {
                ans++;
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}