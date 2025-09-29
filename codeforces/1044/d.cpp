#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1; 
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), pre(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b[i] = a[i] + i;
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> lg(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(30));

    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        f[i][0] = i;
    }

    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int left = f[i][j - 1];
            int right = f[i + (1 << (j - 1))][j - 1];
            f[i][j] = (b[left] >= b[right] ? left : right);
        }
    }

    auto query = [&](int L, int R) {
        int k = lg[R - L + 1];
        int left = f[L][k];
        int right = f[R - (1 << k) + 1][k];
        return (b[left] >= b[right] ? left : right);
    };

    auto dfs = [&](auto&& dfs, int l, int r) -> int {
        int pos = query(l, r);
        int x = std::min(a[pos], pos - l);
        if (x > 2) {
            return dfs(dfs, l, pos - 2) + dfs(dfs, pos, r) + a[pos - 1] - x;
        } 
        return pre[r] - pre[l - 1] - (r - l);
    };

    std::cout << dfs(dfs, 1, n) << '\n';

}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}