#include <bits/stdc++.h>
#define int long long

int sum(int n) {
    if (n <= 0) return 0;
    int res = 0, base = 1;
    while (base <= n) {
        int l = n / (base * 10);
        int c = (n / base) % 10;
        int r = n % base;
        res += l * 45 * base;
        res += c * (c - 1) / 2 * base;
        res += c * (r + 1);
        base *= 10;
    }
    return res;
}

void solve() {
    int k;
    std::cin >> k;
    int d = 1, len = 9, rem = k;
    while (rem > d * len) {
        rem -= d * len;
        d++;
        len *= 10;
    }
    int st = 1;
    for (int i = 1; i < d; i++) {
        st *= 10;
    } 
    int cnt = (rem - 1) / d;
    int pos = (rem - 1) % d;
    int x = st + cnt;
    int ans = sum(x - 1);
    std::string s = std::to_string(x);
    for (int i = 0; i <= pos; i++) {
        ans += s[i] - '0';
    }
    std::cout << ans << "\n";
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
