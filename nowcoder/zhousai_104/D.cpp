#include <bits/stdc++.h>
#define int long long
int a[510][510];

signed main() {
    int n, m;
    int ans = 0;
    std::vector<int> ans1;
    std::map<int, int> mp;
    std::cin >> n >> m;
    std::map<std::pair<int, int>, int> mmp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            if (a[i][j] == std::min(i, j)) {
                ans++;
            } else {
                if (mmp.count({a[i][j], std::min(i, j)})) {
                    cnt = 2;
                }
                ans1.push_back(std::min(i, j));
                mp[a[i][j]]++;
                mmp[{std::min(i, j), a[i][j]}]++;
            }
        }
    }
    if (cnt) {
        std::cout << ans + 2 << '\n';
        return 0;
    }
    for (auto x : ans1) {
        if (mp.count(x)) {
            mp[x]--;
            ans++;
            if (mp[x] == 0) mp.erase(x);
            cnt++;
        }
        if (cnt) {
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
} 