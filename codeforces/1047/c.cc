#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    if ((a & 1) && (b & 1)) {
        cout << a * b + 1 << '\n';
    } else {
        if (b & 1) {
            cout << "-1\n";
        } else if (a & 1) {
            if (b % 4 == 0) {
                cout << a * (b / 2) + 2 << '\n';
            } else {
                cout << "-1\n";
            }
        } else {
            cout << a * (b / 2) + 2 << '\n';
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