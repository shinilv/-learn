#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](std::string& s) -> bool {
        if (s.size() < n) return false;
        int cnt = 0;
        for (auto x : s) cnt += (x == '(');
        int t = 0;
        for (int i = 1; i <= n; i++) {
            int p = a[i];
            p--;
            if (s[i - 1] == '(') cnt--;
            if (p != t + cnt) {
                return false;
            }
            if (s[i - 1] == ')') t++;
        }
        return true;
    };

    std::string ans1, ans2;
    ans1 = "(";
    ans2 = ")";
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            if (ans1.size() == i - 1) {
                ans1 += ans1.back() == '(' ? ')' : '(';
            }
            if (ans2.size() == i - 1) {
                ans2 += ans2.back() == '(' ? ')' : '(';
            }
        } else if (a[i] == a[i - 1] + 1) {
            if (ans1.size() == i - 1 && ans1.back() == ')') {
                ans1 += ')';
            }
            if (ans2.size() == i - 1 && ans2.back() == ')') {
                ans2 += ')';
            }
        } else if (a[i] == a[i - 1] - 1) {
            if (ans1.size() == i - 1 && ans1.back() == '(') {
                ans1 += '(';
            }
            if (ans2.size() == i - 1 && ans2.back() == '(') {
                ans2 += '(';
            }
        } else {
            std::cout << "0\n";
            return;
        }
        if (ans1.size() < i && ans2.size() < i) {
            std::cout << "0\n";
            return;
        }
    }
    int ans = check(ans1) + check(ans2);
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    } 
    return 0;
}