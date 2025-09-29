#include <bits/stdc++.h>
using namespace std;
int p[1000010];
int find(int x ) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            ans++;
        } else {
            p[find(u)] = find(v);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            ans++;
            p[find(1)] = find(i);
        }
    }
    cout << ans << '\n';
    return 0;
}