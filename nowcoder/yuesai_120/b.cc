#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "-1\n";
        return;
    }
    int k = (n & -n);
    if (k == n) {
        cout << n / 2 << '\n';
    } else {
        cout << k << '\n';
    }
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}