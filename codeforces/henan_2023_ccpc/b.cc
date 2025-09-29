#include <bits/stdc++.h>
using namespace std;
#define int long long 

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1; 
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int main() {
    int n = read();
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    suf[n + 1] = INT_MAX;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        pre[i] = max(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }

    auto check = [&](int k) -> bool {
        for (int i = 1; i <= n; i += k) {
            if (pre[min(n, i + k - 1)] > suf[min(n + 1, i + k)]) return false;
        }
        return true; 
    };


    if (check(1)) {
        cout << n << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (check(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}