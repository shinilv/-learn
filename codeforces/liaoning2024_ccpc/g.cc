#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    vector<int> l(n + 1, 1), r(n + 1, n);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.back()] < a[i]) {
            // cout << i << '\n';
            r[st.back()] = i - 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i >= 1; i--) {
        while (st.size() && a[st.back()] <= a[i]) {
            l[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
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

    vector<vector<int>> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        mp[a[i]].push_back(i);
    }
    auto func = [&](int x) -> int {
        int res = 0;
        for (int i = 0; i + k <= mp[x].size(); i++) {
            int ll = mp[x][i], rr = mp[x][i + k - 1];
            int k1 = ll - l[ll] + 1, k2 = r[rr] - rr + 1;
            if (query(ll, rr) <= x) {
                res += (k1 * k2);
            }
        }
        return res;
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i].size() >= k) {
            ans += func(i);
        }
    }
    cout << ans << '\n';
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