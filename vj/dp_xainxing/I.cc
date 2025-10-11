#include <bits/stdc++.h>
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n + 1);
    int sx, sy;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] = ' ' + a[i];
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*') {
                sx = i, sy = j;
            }
        }
    }
    int q;
    std::cin >> q;
    std::string s;
    std::cin >> s;
    int v = 0, dir = 0;
    for (auto x : s) {
        int t = 0;
        if (x == 'U') {
            v++;
        } else if (x == 'D') {
            v = std::max(0, v - 1);
        } else if (x == 'L') {
            if (dir == 0) dir = 7;
            else dir--;
        } else {
            if (dir == 7) dir = 0;
            else dir++;
        }
        int cnt = v;
        int tx = dx[dir], ty = dy[dir];
        while (cnt) {
            int xx = sx + tx, yy = sy + ty;
            if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == '#' || ((dir & 1) && (a[xx][sy] == '#' && a[sx][yy] == '#'))) {
                t = 1;
                v = 0;
                break;
            }
            sx = xx, sy = yy;
            cnt--;
        }
        
        if (t) std::cout << "Crash! " << sx << ' ' << sy << '\n';
        else std::cout << sx << ' '  << sy << '\n';
    }

    return 0;
}