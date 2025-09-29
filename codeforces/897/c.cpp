#include <bits/stdc++.h>
#define int long long

/*
思路： 理解题意发现并不难， 如果s[0] > 1, 则R最大为1
如果是序列 0 1 2 3， 则R最大是4。
不多说了，看代码吧
*/

void solve() {
    int n;
    std::cin >> n;
    int x;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        mp[x]++;
    }
    int p = 0;
    for (int i = 0; i <= n; i++) {
        if (!mp.count(i)) {
            p = i;
            break;
        }
    }
    while (1) {
        std::cout << p << std::endl;
        int q;
        std::cin >> q;
        if (q == -1) {
            break;
        }
        p = q;
    }
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}