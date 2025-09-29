#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = LLONG_MAX / 2;
    multiset<int> se;
    for (int l = 1, r = 1; r < n; ) {
        se.insert(a[r + 1] - a[r]);
        r++;
        if (r - l + 1 == k) {
            ans = min(ans, (*se.begin()) * (a[r] - a[l]));
            se.erase(se.find(a[l + 1] - a[l]));
            l++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}