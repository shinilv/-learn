#include <bits/stdc++.h>
using namespace std;
#define int long long

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int s =0;
    int lc = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lc = lcm(lc, a[i]);
    }
    for (int i = 0; i < n ;i++) {
        s += lc / a[i];
    }
    if (m % s) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        int k = m / s;
        for (auto x : a) {
            cout << k * (lc / x) << ' ';
        }
        cout << '\n';
    }


    return 0;
}