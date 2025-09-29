#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::set<int> se1, se2;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 1) {
            se1.insert(i);
        } else if (a[i] == 2) {
            se2.insert(i);
        }
    }
    std::vector<std::array<int, 2>> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0 && se1.size()) {
            auto it = se1.begin();
            if (*it > i) {
                break;
            }
            ans.push_back({i, *it});
            a[*it] = 0;
            se1.erase(it);
            a[i] = 1;
        } 
        if (a[i] == 1 && se2.size()){
            auto it = se2.begin();
            if (*it > i) {
                continue;
            }
            ans.push_back({i, *it});
            a[*it] = 1;
            se1.insert(*it);
            se2.erase(it);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto& [l, r] : ans) {
        std::cout << l + 1 << ' ' << r + 1 << '\n';
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