#include <bits/stdc++.h>
#define int long long

void solve() {
    int n, k, l, r;
    std::cin >> n >> k >> l >> r;
    std::vector<int> a(n), p1(n, n + 1), p2(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::map<int, int> mp;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && j - i + 1 <= r && mp.size() < k) {
            mp[a[j++]]++;
        }
        if (mp.size() == k) {
            p1[i] = j - 1;
        } 
        p1[i] = std::max(p1[i], i + l - 1);
        mp[a[i]]--;
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }
    }
    k++;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && j - i + 1 <= r && mp.size() < k) {
            mp[a[j++]]++;
        }
        if (mp.size() == k) {
            p2[i] = j - 1;
        } else {
            p2[i] = j;
        }
        mp[a[i]]--;
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::max(0LL, p2[i] - p1[i]);
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}