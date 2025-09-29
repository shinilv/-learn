#include <bits/stdc++.h>

void solve() {
    std::string s, t, p;
    std::cin >> s >> t >> p;
    bool ok = false;
    int cnt[26]{};
    for (auto x : s) cnt[x - 'a']++;
    for (auto x : t) cnt[x - 'a']--;
    for (auto x : p) cnt[x - 'a']++;
    for (int i = 0, j = 0; i < t.size(); i++) {
        if (t[i] == s[j] && ++j == s.size()) {
            ok = true;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] < 0) ok = false;
    }
    if (ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}