#include <bits/stdc++.h>
#define int long long

int query(int x) {
    std::cout << "? " << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i += k) {
        if (i + k - 1 > n) {
            int m = n - i + 1;
            ans = ans ^ query(n - m / 2 - k + 1) ^ query(n - k + 1);
            break;
        }
        // std::cout << "!!!" << i << '\n';
        ans ^= query(i);
    }
    std::cout << "! " <<  ans << std::endl;

}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}