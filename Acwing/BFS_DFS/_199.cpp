#include <bits/stdc++.h>
int r, c;
char s[200][200];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    std::cin >> c >> r;
    int sx, sy, ex, ey;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> s[i][j];
            if (s[i][j] == 'K') {
                sx = i, sy = j;
            } 
            if (s[i][j] == 'H') {
                ex = i, ey = j;
            }
        }
    }
    std::vector<std::vector<int>> dis(r, std::vector<int> (c, INT_MAX / 2));

    std::queue<std::array<int, 2>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;

    while (q.size() ){
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (tx >= 0 && ty >= 0 && tx < r && ty < c && s[tx][ty] != '*' && dis[x][y] + 1 < dis[tx][ty]) {
                q.push({tx, ty});
                dis[tx][ty] = 1 + dis[x][y];
            }
        }
    }

    std::cout << dis[ex][ey] << '\n';


    return 0;
}