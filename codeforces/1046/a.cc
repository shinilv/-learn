#include <bits/stdc++.h>
using namespace std;
#define int long long

int check(int ta, int tb) {
    int res = 0;
    if (ta > tb) {
        if (ta <= tb * 2 + 2) res = 1;
    } else {
        if (tb <= ta * 2 + 2) res = 1;
    }
    return res;
}

void solve() {
    int a, b, c,d;
    cin >> a >> b >> c >> d;
    int ans = check(a, b) && check(c - a, d - b);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}