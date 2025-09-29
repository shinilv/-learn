#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string ans = "nunhehheh";
    vector<array<int, 2>> vec;
    for (int i = 1; (1LL << i) - 1 <= n; i++) {
        vec.push_back({(1 << i) - 1, i});
    }
    if (n == 0) {
        cout << ans << '\n';
        return;
    }
    sort(vec.begin(), vec.end(), greater<array<int, 2>>());
    vector<array<int, 2>> a;
    while (n) {
        for (auto [k, v] : vec) {
            if (k <= n) {
                n -= k;
                if (a.size() && a.back()[0] == v) {
                    a.back()[1]++;
                } else {
                    a.push_back({v, 1});
                }
                break;
            }
        }
    }
    string s(1000000, 'h'), t(a[0][0], 'a');
    ans += t;
    for (auto [idx, v] : a) {
        int p = ans.size() - idx;
        if (idx == a[0][0]) v--;
        ans.insert(p, s.substr(0, v));
    }
    cout << ans << '\n';
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
