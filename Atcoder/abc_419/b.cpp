#include <bits/stdc++.h>
#define int long long

signed main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x;
            std::cin >> x;
            pq.push(x);
        } else {
            std::cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
} 