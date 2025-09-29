#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    int mi = INT_MAX, mx = INT_MIN;
    for (auto x : a) {
        mi = min(mi, x);
        mx = max(mx, x);
        mp[x]++;
        if (mp.size() > 2) {
            cout << mi + mx << ' ';
        } else {
            if (mp[mi] == 1) {
                cout << mx * 2 << ' ';
            } else {
                cout << mx + mi << ' ';
            }
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}