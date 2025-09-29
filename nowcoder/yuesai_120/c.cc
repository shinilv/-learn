#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
    } else {
        if (n == 2) {
            cout << "-1\n";
        } else {
            cout << "1 3 2 4 ";
            for (int i = 5; i <= n; i++) {
                cout << i << " \n"[i == n];
            }
        }
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