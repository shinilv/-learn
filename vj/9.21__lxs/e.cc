#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    if (k <= (s[0] - 'a')) {
        int t = s[0] - 'a';
        char c = (t - k) + 'a';
        for (auto& ch : s) {
            if (ch - 'a' <= t) {
                ch = std::min(ch, c);
            }
        }
        std::cout << s << '\n';
    } else {
        k -= (s[0] - 'a');
        int t = s[0] - 'a';
        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' <= t) {
                s[i] = 'a';
            } else {
                int p = s[i] - 'a' - t;
                if (k >= p) {
                    k -= p;
                    t = s[i] - 'a';
                    s[i] = 'a';
                } else {
                    int v = s[i] - 'a';
                    char c = (v - k) + 'a';
                    for (int j = i; j < n; j++) {
                        if (s[j] - 'a' <= t) s[j] = 'a';
                        else if (s[j] - 'a' <= v) {
                            s[j] = std::min(s[j], c);
                        }
                    }
                    std::cout << s << '\n';
                    return;
                }
            }
        }
        std::cout << s << '\n';
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