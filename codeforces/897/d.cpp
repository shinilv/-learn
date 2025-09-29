#include <bits/stdc++.h>
#define int long long

/*
思路： 找环， 建有向边 i -> a[i]， 表示第 i 个要变为 a[i],  
通过观察 如果存在一个环的大小不等于k， 这个是肯定不可以构造成功的， k = 1 的时候特判一下 
*/

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        a[i] = x;
        if (i != x) f = 1;
    }

    if (f && k == 1) {
        std::cout << "NO\n";
        return;
    }

    std::vector<int> vis(n + 1);
    std::vector<int> st(n + 1);

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            int cnt = 0;
            for (int j = i; ; j = a[j]) {
                if (st[j] && st[j] != i) {
                    cnt = k;
                    break;
                }
                st[j] = i;
                vis[j]++;
                if (vis[j] == 3) {
                    break;
                }
                if (vis[j] == 2) {
                    cnt++;
                }
            }
            if (cnt != k) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    std::cout << "YES\n";
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
