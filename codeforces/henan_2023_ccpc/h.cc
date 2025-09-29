#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> k >> n;
    int t = k * 2;
    int ans1 = 0;
    if (n <= t) {
        ans1 = (t - n) / 2 + 1;
    }
    int ans2 = min(n, t) + (max(0LL, t - n) / 2);
    cout << ans1 << ' ' << ans2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}