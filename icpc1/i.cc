#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, V, st;
    cin >> n >> m >> V >> st;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<array<int, 2>> dis(n + 1, {INT_MAX, 0});
    dis[st] = {1, 0};
    queue<int> q;
    q.push(st);
    while (q.size()) {
        auto t = q.front();
        auto [cnt, k] = dis[t];
        q.pop();
        for (auto [y, w] : g[t]) {
            int cnt1 = cnt, k1 = k;
            if (w + k > V) {
                cnt1++;
                k1 = w;
            } else {
                if (w + k == V) {
                    cnt1++;
                    k1 = 0;
                } else {
                    k1 = k + w;
                }
            }
            if (cnt1 < dis[y][0] || (cnt1 == dis[y][0] && k1 < dis[y][1])) {
                q.push(y);
                dis[y] = {cnt1, k1};
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i][0] == INT_MAX) {
            cout << "-1 ";
            continue;
        }
        int tt = dis[i][0];
        if(tt > 1 && dis[i][1] == 0) {
            tt--;
        }
        cout << tt << ' ';
    }
    cout << '\n';
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}