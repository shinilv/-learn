#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    if (n == 4) {
        cout << "-1\n";
        return;
    } 
    if (n == 2) {
        cout << "1 2\n";
        return;
    }
    if (n == 3) {
        cout << "1 2\n";
        cout << "2 3\n";
        return;
    }
    int t = (n - 3) / 2;
    for (int i = 1; i < n - t; i++) {
        cout << i << ' ' << i + 1 << '\n';
    }
    int x = n - t + 1;
    for (int i = 2; x <= n; i++, x++) {
        cout << i << ' ' << x << '\n';
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