#include <bits/stdc++.h>
#define int long long

int query(std::vector<int>& a) {
    std::cout << "? " << a.size() << ' ';
    for (auto x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> t, vis(2 * n + 1), p, ans(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        t.push_back(i);
        int res = query(t);
        if (res != 0) {
            t.pop_back();
            ans[i] = res;
            p.push_back(i);
        } else {
            vis[i] = 1;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        std::vector<int> tem = p;
        if (vis[i] == 1) { 
            tem.push_back(i);
            ans[i] = query(tem);
        }   
    }
    std::cout << "! ";
    for (int i = 1; i <= 2 * n; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}