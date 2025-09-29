#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, k;
    cin >> n >> k;

    
    for (int i = n; i >= n - k; i--) {
        cout << i << ' ';
    }
    cout << '\n';
    
}

signed main() {
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}