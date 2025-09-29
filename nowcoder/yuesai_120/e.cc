#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i <n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    vector<int> ans(n + 1, -1);
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i < n; i++) {
        while (st.size() && a[i][0] % a[st.back()][0] == 0) {
            st.pop_back();
        }
        if (st.size()) {
            ans[a[i][1]] = a[st.back()][1];
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }

}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}