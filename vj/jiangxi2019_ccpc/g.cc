#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(3001);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int ans = 0; ans < 2000; ans++) {
        int f = 0;
        for (auto x : a) {
            if (cnt[x + ans]) {
                f = 1;
                break;
            }
        } 
        if (!f) {
            cout << ans << '\n';
            break;
        }
    }
    return 0;
}