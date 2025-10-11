#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> suf(n + 2), pre(n + 1);
    int cnt = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (s[i - 1] == '0') cnt++;
        else if (s[i - 1] == '?') suf[i] += cnt, sum++;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        if (s[i] == '1') cnt++;
        else if (s[i] == '?') pre[i + 1] += cnt;
    }
    int ans = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (s[i] == '1');
        if (s[i] == '0') ans += cnt;
    }
    int res = ans + pre[n];
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '?') {
            t++;
            int x = t * (sum - t) + suf[1] - suf[i + 1] + pre[n] - pre[i];
            res = std::max(res, ans + x);
        }
    }
    std::cout << res << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
} 