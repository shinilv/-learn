#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        mp[a[i]].push_back(i);
    }
    vector<int> ans(n);
    int t = 1;
    for (auto [k, v] : cnt) {
        if (v % k) {
            cout << "-1\n";
            return;
        }
        int cnt = 0;
        for (auto x : mp[k]) {
            ans[x] = t;
            cnt++;
            if (cnt == k) {
                cnt = 0, t++;
            }
        }
    }
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