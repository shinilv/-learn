#include <bits/stdc++.h>

/*
题意： 转化题意就是求 全部无洞正方形子矩阵的数量
    把有洞的方格设为 0， 其他设为 1 统计全为 1 的正方形子矩阵问题就转化为 这道题：https://leetcode.cn/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2025-08-20
    这道题正好是今天 leetcode 的每日一题
    可以看这一篇题解：https://leetcode.cn/problems/count-square-submatrices-with-all-ones/solutions/3751608/tu-jie-dong-tai-gui-hua-jian-ji-xie-fa-p-1kiy/?envType=daily-question&envId=2025-08-20
    以下是示例代码
*/

const int N = 3010;
int a[N][N];
long long dp[N][N];

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    while (k--) {
        int x, y;
        std::cin >> x >> y;
        a[x][y] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ans += dp[i][j];
            }
        }
    }
    std::cout << ans << '\n';

    return 0;
}