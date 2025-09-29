#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i && a.back()[1] == x) {
            a.back()[1]++;
        } else {
            a.push_back({x, 1});
        }
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (i && b.back()[1] == x) {
            b.back()[1]++;
        } else {
            b.push_back({x, 1});
        }
    }
    if (a.size() != b.size()) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        auto [x, y] = a[i];
        auto [x1, y1] = b[i];
        if (x != x1 || y > y1) {
            cout << "-1\n";
            return;
        }
        int cnt = 0;
        while (y < y1) {
            y *= 2;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}