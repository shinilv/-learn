#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 0});
    }
    
    // dp[i][j] 表示从节点 1 到节点 i，经过 j 次"特殊边"的最小路径
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, LLONG_MAX / 2));
    dp[1][0] = 0;
    
    // 优先队列，保存当前的最短路径状态
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, 1});  // 初始状态，节点 1，经过 0 次特殊边，最短路径为 0
    
    // 用一个 visited 数组避免冗余的状态更新
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    
    while (!pq.empty()) {
        auto [d, k, idx] = pq.top();
        pq.pop();
        
        // 如果当前状态已经访问过，则跳过
        if (visited[idx][k]) continue;
        visited[idx][k] = true;

        // 遍历所有相邻节点
        for (auto& [y, w] : g[idx]) {
            if (w == 0) {
                // 处理特殊边，经过 k + 1 次特殊边
                if (k + 1 <= n && d < dp[y][k + 1]) {
                    dp[y][k + 1] = d;
                    pq.push({d, k + 1, y});
                }
            } else {
                // 处理普通边，更新最短路径
                int new_d = d + w;
                if (new_d < dp[y][k]) {
                    dp[y][k] = new_d;
                    pq.push({new_d, k, y});
                }
            }
        }
    }

    // 动态规划最终更新
    for (int i = 0; i <= n; i++) {
        int sum = 0;
        // 通过懒更新避免重复计算
        for (int j = 1; j <= n; j++) {
            if (i) dp[j][i] = min(dp[j][i], dp[j][i - 1]);
            sum += dp[j][i];
        }
        cout << sum << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
