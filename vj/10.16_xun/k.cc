#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    std::vector<std::array<int, 2>> vec(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int cnt = 0;
        len += a.size();
        for (auto x : a[i]) {
            if (x == '(') {
                cnt++;
            } else {
                if (cnt) cnt--;
                else vec[i][0]++;
            }
        }
        vec[i][1] = cnt;
    }
    std::vector<int> memo(1 << n, -1);
    auto dfs = [&](auto&& dfs, int mask, int t) -> int {
        if (mask == ((1 << n) - 1)) {
            return t == 0;
        }
        int& res = memo[mask];
        if (res != -1) {
            return res;
        }
        res = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1) && t >= vec[i][0]) {
                res = (res + dfs(dfs, mask | (1 << i), t + vec[i][1] - vec[i][0])) % MOD;
            }
        }
        return res;
    };

    std::cout << dfs(dfs, 0, 0) << '\n'; 
    
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}