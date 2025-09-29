#include <bits/stdc++.h>

/*
思路： 统计每一天有空的人数， 取有空人数 = n 的天 连续的最大值
*/

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> cnt(m);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'o') {
                cnt[j]++;
            }
        }
    }
    int ans = 0, t = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[i] == n) {
            t++;
            ans = std::max(ans, t);
        } else {
            t = 0;
        }
    }
    std::cout << ans << '\n';
    return 0;
}