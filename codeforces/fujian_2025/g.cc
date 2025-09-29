#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pre(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[1];
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + max(0LL, a[i] - a[i - 1]);
    }
    int k; cin >> k;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << k << '\n';
            continue;
        }
        cout << k + pre[r] - pre[l] << '\n';
    }
    return 0;
}