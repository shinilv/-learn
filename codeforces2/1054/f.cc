#include <bits/stdc++.h>
#define int long long

void solve() {
    int h, d;
    std::cin >> h >> d;

    auto check = [&](int x) -> bool {
        int sum = -x;
        int b = d / (x + 1), m = d % (x + 1);
        sum += m * ((b + 2) * (b + 1) / 2);
        sum += (x + 1 - m) * (b * (b + 1) / 2);
        return sum < h;
    };

    int l = 0, r = d * 2;

    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << l + d << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}