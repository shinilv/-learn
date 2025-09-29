#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> f(n + 1);
    while (q--) {
        int t, l;
        cin >> t >> l;
        f[l]++;
        int r = min(n - 1, l + t - 1);
        if (r == n - 1) {
            int x = t - (n - l);
            int p = x / n;
            f[0] += p;
            f[n] -= p;
            f[0]++;
            f[x % n]--;
        }
        f[r + 1]--;
    }
    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }
    for (int i =0; i < n; i++) {
        cout << f[i] << ' ';
    }
    cout << '\n';
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