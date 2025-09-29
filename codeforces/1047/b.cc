#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int p = 3;
    for (int i = 3; ; i++) {
        if ((n - n / i) % (i - 1) == 0) {
            p = i;
            break;
        }
    }
    vector<int> cnt[p];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i % p].push_back(i);
    }
    // cout << cnt[1].size() << ' ' << cnt[2].size() << '\n';
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int t = (p - a[i] % p) % p;
        ans.push_back(cnt[t].back());
        cnt[t].pop_back();
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