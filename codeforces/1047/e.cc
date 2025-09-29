#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int t = 0;
    for (auto [k1, v] : cnt) {
        if (k1 != t) {
            break;
        }
        t++;
    }
    int p = t, c = 0;
    int sum = 0;
    for (auto [k1, v] : cnt) {
        if (v > 1 && p > k1) {
            p = k1;
        } 
        if (v > 1 || k1 > t) {
            ans += v * t;
        } else {
            ans += k1;
        }
    }
    for (auto [k1, v] : cnt) {
        if (v > 1 || k1 >= p) {
            c += v;
        } else {
            sum += k1;
        }
    }
    if (k == 1) {
        cout << ans << '\n';
        return;
    }
    k--;
    
    if (p == t) {
        if (k & 1) {
            ans = sum + c * (t + (c != 1));
        } else ans = sum += c * t;
    } else {
        if (k & 1) ans = sum + c * p;
        else ans = sum + c * (p + 1);
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