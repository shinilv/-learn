#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]]++;
    }
    int p = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            p = 1;
            break;
        }
    }
    if (!p || mp.size() == 1) {
        for (int i = n - 1; i >= 0; i--) {
            std::cout << a[i] << " \n"[i == 0];
        }
        return;
    }
    int l = -1, r = -1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] > a[j]) {
                l = j, r = i;
                break;
            }
        }
        if (l != -1) {
            break;
        }
    }
    std::swap(a[l], a[r]);
    sort(a.begin() + l + 1, a.end());
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}