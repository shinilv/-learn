#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        pq.push(x);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int a = pq.top();
        if (a == 0) {
            break;
        }
        pq.pop();
        int b =pq.top();
        pq.pop();
        ans += a;
        pq.push(0);
    }
    std::cout << ans << '\n';
}

signed main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
