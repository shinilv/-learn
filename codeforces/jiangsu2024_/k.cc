#include <bits/stdc++.h>
using namespace std;
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int s = 0;
    for (int l = 1, r = 1; r <= n; ){
        s += a[r];
        r++;
        if (r - l == k) {
            double x = (double)s / k;
            // cout << s << '\n';
            if (x >= 1024) {
                int m = x / 1024;
                double m1 = x - (m * 1024);
                double ans = m + m1 / 1024;
                printf("%.6f", ans);
                cout << " MiBps\n";
            } else {
                printf("%.6f", x);
                cout << " KiBps\n";
            }
            s -= a[l];
            l++;
        }
    }
    return 0;
}