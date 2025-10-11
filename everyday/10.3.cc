#include <bits/stdc++.h>

struct HashSeq {
    typedef unsigned __int128 u128;
    static const u128 BASE1 = 131, BASE2 = 13331;

    std::vector<u128> P1, H1, P2, H2;

    HashSeq(std::string& s) {
        int n = s.size();
        P1.resize(n + 1), H1.resize(n + 1);
        P2.resize(n + 1), H2.resize(n + 1);
        P1[0] = P2[0] = 1;
        H1[0] = H2[0] = 0;
        for (int i = 1; i <= n; i++) {
            P1[i] = P1[i-1] * BASE1;
            H1[i] = H1[i-1] * BASE1 + s[i-1];
            P2[i] = P2[i-1] * BASE2;
            H2[i] = H2[i-1] * BASE2 + s[i-1];
        }
    }

    std::pair<u128,u128> query(int l, int r) {
        u128 h1 = H1[r] - H1[l-1] * P1[r-l+1];
        u128 h2 = H2[r] - H2[l-1] * P2[r-l+1];
        return {h1, h2};
    }
};


void solve() {
    std::string s, p;
    std::cin >> s;
    int n = s.size();
    p = s;
    reverse(p.begin(), p.end());
    HashSeq hs(s), rhs(p);
    int t = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            break;
        } 
        t++;
    }
    if (t >= n / 2) {
        std::cout << s << '\n';
        return;
    }
    std::string ans1, ans2; 
    for (int i = n - t; i > t; i--) {
        if (hs.query(t + 1, i) == rhs.query(n - i + 1, n - t)) {
            ans1 = s.substr(0, t) + s.substr(t, i - t) + s.substr(n - t);
            break;
        }
    }
    for (int i = t + 1; i <= n - t; i++) {
        if (hs.query(i, n - t) == rhs.query(n - (n - t) + 1, n - i + 1)) {
            ans2 = s.substr(0, t) + s.substr(i - 1);
            break;
        }
    }
    std::cout << (ans1.size() > ans2.size() ? ans1 : ans2) << std::endl;
}

int main() {
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}