#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum & 1) {
        cout << "-1\n";
        return;
    }
    int res = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
        if (res >= sum / 2) {
            pos = i;
            break;
        }
    }
    int t = res - (sum - res);
    if (res > sum / 2) {
        vector<int> v(n);
        int x = t / 2, id = 0;
        for (int i = 0; i <= pos; i++) {
            v[i] = min(x, a[i]);
            x -= min(x, a[i]);
            if (x == 0) {
                id = i + 1;
                break;
            }
        }
        if (id > pos) {
            cout << "-1\n";
            return;
        }
        x = t / 2;
        for (int i = id; i <= pos; i++) {
            v[i] = min(x, a[i]);
            x -= min(x, a[i]);
            if (x == 0) {
                break;
            }
        }
        cout << 2 << '\n';
        for (int i = 0; i < n; i++) {
            cout << v[i] << ' ';
            a[i] -= v[i];
        }
        cout << '\n';
    } else {
        cout << 1 << '\n';
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}