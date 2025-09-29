#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = INT_MIN, mi = INT_MIN, mx2 = INT_MIN, mi2 = INT_MIN;
    int ans = n - (n % 2 == 0) - 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i & 1) {
            sum -= a[i];
            mx = max(mx, 2 * a[i] - i);
            mx2 = max(mx2, 2 * a[i] + i);
        } else {
            sum += a[i];
            mi = max(mi, -2 * a[i] + i);
            mi2 = max(mi2, -2 * a[i] - i);
        }
    }
    
    cout << sum + max(max(mx + mi, mx2 + mi2), ans) << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}