#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> st, r(n + 1), l(n + 1);
    st.push_back(1);
    for (int i = 2; i <= n; i++) {
        while (st.size() && a[i] % a[st.back()]) {
            r[st.back()] = i - 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (st.size()) st.pop_back();
    st.push_back(n);
    for (int i = n - 1; i >= 1; i--) {
        while (st.size() && (a[i] % a[st.back()] || a[i] == a[st.back()])) {
            l[st.back()] = i + 1;
            st.pop_back();
        }
        st.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << ans << ' ' << l[i] << ' ' << r[i] << '\n';

        if (l[i] == 0) l[i] = 1;
        if (r[i] == 0) r[i] = n;
        ans += (r[i] - i + 1) * (i - l[i] + 1);
        // cout << ans << ' ' << l[i] << ' ' << r[i] << '\n';
    }
    cout << ans << '\n';
    return 0;
}