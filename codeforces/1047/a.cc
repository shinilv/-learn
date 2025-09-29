#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int k, x;
    cin >> k >> x;
    while (k--) x *= 2;
    cout << x << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}