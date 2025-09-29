#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1), ans;
    int rt = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        if (x == i) {
            rt = i;
        } else {
            g[x].push_back(i);
        }
    }
    int idx = 0;
    auto dfs = [&](auto&& dfs, int u, int f, int pos) -> void {
        if (!f) {
            ans.push_back({});
        }
        ans[pos].push_back(u);
        int x = 0;
        for (auto y : g[u]) {
            if (!x) {
                dfs(dfs, y, 1, pos);
                x++;
            } else {
                idx++;
                dfs(dfs, y, 0, idx);
            }
        }
    };

    dfs(dfs, rt, 0, 0);

    std::cout << ans.size() << '\n';
    for (auto& arr : ans) {
        std::cout << arr.size() << '\n';
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " \n"[i == arr.size() - 1];
        }
    }


}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}