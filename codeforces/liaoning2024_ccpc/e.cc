#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    if ((n * m) % 4) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> a(n, vector<int>(m));
    int idx = 1, cnt = 0;
    if (n % 4 == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[j][i] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
        }
    } else if (m % 4 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
        }
    } else if ((n - 2) && (n - 2) % 4 == 0) {
        swap(n, m);
        vector<vector<int>> b(n, vector<int>(m));
        a = b;
        for (int i = 0; i < n; i += 2) {
            a[i][0] = idx, a[i][1] = idx, a[i][2] = idx, a[i +1][0] = idx++;
            a[i][m - 1] = a[i][m - 2] = a[i][m - 3] = a[i + 1][m - 1] = idx++;
            for (int j = 1; j < m - 1; j ++) {
                a[i + 1][j] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
            for (int j = 3; j < m - 3; j++) {
                a[i][j] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
        }
        cout << "YES\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[j][i] << ' ';
            }
            cout << '\n';
        }
        return;
    } else if ((m - 2) && (m - 2) % 4 == 0) {
        for (int i = 0; i < n; i += 2) {
            a[i][0] = idx, a[i][1] = idx, a[i][2] = idx, a[i +1][0] = idx++;
            a[i][m - 1] = a[i][m - 2] = a[i][m - 3] = a[i + 1][m - 1] = idx++;
            for (int j = 1; j < m - 1; j ++) {
                a[i + 1][j] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
            for (int j = 3; j < m - 3; j++) {
                a[i][j] = idx;
                cnt++;
                if (cnt == 4) {
                    idx++, cnt = 0;
                }
            }
        }
    } else {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto& x : a) {
        for (int i = 0; i < m; i++) {
            cout << x[i] << " \n"[i == m - 1];
        } 
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}