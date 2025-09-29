#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> ff(n + 1);
    vector<vector<int>> g(100001);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i], t = 0;
        while (x) {
            t++, x /= 2;
        }
        ff[i] = ff[i - 1] + t;
        g[a[i]].push_back(i);
    }

    vector<int>lg(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(30));
    lg[1] = 0;
    for(int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for(int i = 1; i <= n; i++) {
        f[i][0] = a[i];
    }
    for(int j = 1; j <= lg[n]; j++) {
        for(int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto query = [&](int x, int y) {
        int l = lg[y - x + 1];
        return max(f[x][l], f[y - (1 << l) + 1][l]);
    };

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        if (ff[r] - ff[l - 1] <= k) {
            cout << "0\n";
        } else {
            int t = query(l, r);
            vector<int> cnt(t + 1);
            while (k >= 0) {
                if (t < 0) {
                    cout << "0\n";
                    break;
                } 
                if (g[t].empty() || g[t][0] > r && g[t].back() < l) {
                    k -= cnt[t];
                    cnt[t / 2] += cnt[t];
                } else {
                    int p = upper_bound(g[t].begin(), g[t].end(), r) - lower_bound(g[t].begin(), g[t].end(),l);
                    cnt[t / 2] += p;
                    k -= (p + cnt[t]);
                }
                if (k < 0) {
                    cout << t << '\n';
                    break;
                }
                t--;
            }
        }
    } 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}