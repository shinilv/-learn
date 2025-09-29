#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    int a1, b1, a2, b2;
    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
    int st = a * 60 + b;
    auto check = [&](int l, int r) -> int {
        int tt = l * 60 + r;
        int res = 0;
        int t = 0;
        for (int i = tt; ; i++) {
            if (i == 720) {
                i = 0;
            } 
            if (i == st) break;
            t++;
        }
        res = t;
        t = 0;
        for (int i = tt; ; i--) {
            if (i == -1) {
                i = 719;
            }
            if (i == st) break;
            t++;
        }
        res = min(t, res);


        t = 0;
        int res1 = 0;
        for (int i = r; ; i++) {
            if (i == 60) {
                i = 0;
            } 
            if (i == b) break;
            t += 12;
        }
        res1 = t;
        t = 0;
        for (int i = r; ; i--) {
            if (i == -1) {
                i = 59;
            }
            if (i == b) break;
            t += 12;
        }

        res1 = min(t, res1);
        return res1 + res;
    };


    int ans1 = a1, ans2 = b1;

    for (int i = a1; i <= a2; i++) {
        int s = 0, t = 59;
        if (i == a1) s = b1;
        if (i == a2) t = b2;
        for (int j = s; j <= t; j++)  {
            if (check(i, j) < check(ans1, ans2)) {
                ans1 = i, ans2 = j;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}