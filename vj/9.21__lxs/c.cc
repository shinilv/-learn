#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int cnt1 = 0;
    for (auto ch : s) cnt1 += (ch == '1');
    int ans = 0;
    for (auto ch : s) {
        cnt1 -= (ch == '1');
        if (ch == '1' && cnt1 == 0) ans++;
        else if (cnt1 == 0) {
            ans++;
        }
        if (ch == '0') break;
    }
    std::cout << ans << '\n';

}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}