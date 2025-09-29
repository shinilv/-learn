#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ans(n);
    int cnt = 1, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans[i] = cnt++;
            t++;
            if (t == k) {
                cout << "NO\n";
                return;
            }
        } else {
            t = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = cnt++;
    }
    cout << "YES\n";
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}