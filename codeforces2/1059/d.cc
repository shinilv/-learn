#include <bits/stdc++.h>
#define int long long

int query(int op, int l, int r) {
    std::cout << op << ' ' << l << ' ' << r << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    int cnt = n * (n + 1) / 2;
    cnt = query(2, 1, n) - cnt;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (query(2, mid, n) != query(1, mid, n)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << "! ";
    std::cout << r - cnt + 1 << ' ' << r << std::endl;
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}