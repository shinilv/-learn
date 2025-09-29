#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(char ch, int k) {
    cout << "? " << ch << ' ' << k << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int k1 = 0, k2 = 0;
    int mi = LLONG_MAX / 2;
    int inf = 1e10;
    for (int i = 0; i < n; i++) {
        int x = a[i][0], y = a[i][1];
        int t = inf - x + inf - y;
        if (mi > t) {
            mi = t;
            k1 = i;
        }
    }
    mi = LLONG_MAX / 2;
    for (int i = 0; i < n; i++) {
        int x = a[i][0], y = a[i][1];
        int t = inf - x + abs(-inf - y);
        if (mi > t) {
            mi = t;
            k2 = i;
        }
    }
    query('U', 1e9);
    query('U', 1e9);
    query('R', 1e9);
    int q1 = query('R', 1e9);
    query('D', 1e9);
    query('D', 1e9);
    query('D', 1e9);
    int q2 = query('D', 1e9);
    int ans = ((q1 + q2) + a[k1][1] - a[k2][1] - 1e9 * 8 + a[k1][0] + a[k2][0]) / 2;
    int ans1 = ((q1 - q2) + a[k1][1] + a[k2][1] + a[k1][0] - a[k2][0]) / 2;
    cout << "! " << ans << ' ' << ans1 << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}