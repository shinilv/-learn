#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int b, t1, a1, t2, a2;
    cin >> b >> t1 >> a1 >> t2 >> a2;
    double ans1 = 0, ans2 = 0;
    if (t1 > t2) {
        int x = t1 - t2;
        int v = b * x;
        if (v <= a2) {
            ans2 += x;
            a2 -= v;
            if (a1 > a2) {
                double tt = ((double)a2 * 2) / b;
                ans2 += tt;
                a1 -= a2;
                ans1 += tt + (double)a1 / b;

            } else {
                double tt = ((double)a1 * 2) / b;
                ans1 += tt;
                a2 -= a1;
                ans2 += tt + (double)a2 / b;
            }
        } else {
            ans2 = (double)a2 / b;
            ans1 = (double) a1 / b;        
        }
    } else {
        int x = t2 - t1;
        int v = b * x;
        if (v <= a1) {
            ans1 += x;
            a1 -= v;
            if (a1 > a2) {
                double tt = ((double)a2 * 2) / b;
                ans2 += tt;
                a1 -= a2;
                ans1 += tt + (double)a1 / b;

            } else {
                double tt = ((double)a1 * 2) / b;
                ans1 += tt;
                a2 -= a1;
                ans2 += tt + (double)a2 / b;
            }
        } else {
            ans2 = (double)a2 / b;
            ans1 = (double) a1 / b;        
        }
    }
    printf("%.7f %.7f\n", ans1, ans2);
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}