#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        std::vector<std::array<int, 2>> st;
        st.push_back({a[i], 0});
        int mx = a[i], cnt = 0;
        for (int j = i + 1; j <= n; j++) {
            int len = 0;
            while (st.size() && st.back()[0] > a[j]) {
                cnt -= st.back()[1];
                len += st.back()[1] + 1;
                st.pop_back();
            }
            if (len == 0) {
                mx = a[j];
            }
            cnt += len;
            st.push_back({mx, cnt});
            ans += cnt;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}