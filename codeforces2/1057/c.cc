#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        mp[x]++;
    }
    int ans = 0, sum = 0, cnt = 0;
    std::vector<int> vec;
    for (auto [k, v] : mp) {
        if (v & 1) {
            v--;
            vec.push_back(k);
        }
        sum += v * k;
        cnt += v;
    }
    if (cnt == 0) {
        std::cout << "0\n";
        return;
    }
    sort(vec.begin(), vec.end());
    if (vec.size() == 0) {
        if (cnt > 2) {
            ans = sum;
        } else {
            ans = 0;
        }
    } else if (vec.size() == 1) {
        if (vec[0] < sum) {
            ans = sum + vec[0];
        } else {
            if (cnt > 2) {
                ans = sum;
            } else {
                ans = 0;
            }
        }
    } else {
        if (cnt > 2) ans = sum;
        if (sum > vec[0]) ans = sum + vec[0];
        for (int i = vec.size() - 1; i > 0; i--) {
            if (sum > vec[i]) ans = std::max(ans, sum + vec[i]); 
            if (sum + vec[i - 1] > vec[i]) {
                ans = std::max(ans, sum + vec[i - 1] + vec[i]);
                break;
            }
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}