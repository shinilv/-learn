#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        a[n] = INT_MAX;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int ans = 0;
        for (int i = n - 1; i >= 0 ;i--) {
            if (a[i + 1] == 0) {
                ans = -1;
                break;
            }
            while (a[i] >= a[i + 1]) {
                a[i] /= 2;
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}