#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    auto check = [&](int x) -> bool {
        multiset<int> se1, se0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                if (se1.empty()) {
                    se0.insert(a[i]);
                } else {
                    if (x <= a[i]) {
                        se1.erase(se1.begin());
                    } else {
                        auto it = se1.lower_bound(x - a[i]);
                        if (it == se1.end()) {
                            return false;
                        } else {
                            se1.erase(it);
                        }
                    }
                }
            } else {
                if (se0.empty()) {
                    se1.insert(a[i]);
                } else {
                    if (x <= a[i]) {
                        se0.erase(se0.begin());
                    } else {
                        auto it = se0.lower_bound(x - a[i]);
                        if (it == se0.end()) {
                            return false;
                        } else {
                            se0.erase(it);
                        }
                    }
                }
            }
        }
        return  true;
    };
    // check(7);
    int l = 1, r = 2e9;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}