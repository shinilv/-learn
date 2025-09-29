#include <bits/stdc++.h>
#define int long long

int query(int x, const std::vector<int>& a) {
    std::cout << "? " << x << ' ' << a.size() << ' ';
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
    std::vector<int> cnt(n + 1);
    std::map<int, std::vector<int>> mp;
    int mx = 0, pos;
    for (int i = 1; i <= n; i++) {
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        cnt[i] = query(i, a);
        mp[cnt[i]].push_back(i);
        if (cnt[i] > mx) {
            pos = i;
            mx = cnt[i];
        }
    }
    std::vector<int> ans;
    ans.push_back(pos);
    mx--;
    while (mx) {
        for (int i = 1; i <= n; i++) if (cnt[i] == mx) {
            if (query(pos, {pos, i}) != 1) {
                ans.push_back(i);
                pos = i;
                break;
            }
        }
        mx--;
    }
    std::cout << "! " << ans.size() << ' ';
    for (auto x : ans) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
