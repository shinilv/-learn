#include <bits/stdc++.h>
#define int long long


signed main() {
    int n, k;
    std::cin >> n >> k;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x & 1) cnt1++;
        else cnt2++;
    }
    if (k < n - 1) {
        std::cout << "-1\n";
        return 0;
    }
    int t = k - n + 1;
    if (cnt2 - 1 < t || cnt1 < cnt2 - t - 1) {
        std::cout << "-1\n";
        return 0;
    }
    std::vector<int> ans;
    for (int i = 0; i < t; i++) {
        std::cout << "2 ";
        cnt2--;
    }
    for (int i = 0; i < cnt1; i++) {
        std::cout << "1 ";
        if (cnt2) {
            std::cout << "2 ";
            cnt2--;
        }
    }
    std::cout << "\n";
    
    return 0;
}
