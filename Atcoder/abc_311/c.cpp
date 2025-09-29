#include <bits/stdc++.h>

/*
思路： 因为有n条边， 所以每个连通块一定存在一个环。任意选择一个开始操作即可，见代码
*/

signed main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> vis(n + 1), ans;
    // 这里i初始可以是 1 - n 的任意值
    for (int i = 1; ; i = a[i]) {
        vis[i]++;
        // 说明这个环都已经全部被加入到ans中了，退出循环
        if (vis[i] == 3) {
            break;
        }
        // 第二次遍历到， 说明这个一定是环中的一个节点
        if (vis[i] == 2) {
            ans.push_back(i);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    return 0;
}