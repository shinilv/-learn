#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> vis(2 * n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            vis[i] = x; vis[x] = i;
        }
        if (a == b) {
            cout << "Yes\n";
            continue;
        }
        if (n > 2)  {
            if (vis[a] != b) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (n == 2) {
            if (a <= n && b <= n || a > n && b > n) {
                cout << "No\n";
            } else {
                if (vis[a] != b) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}