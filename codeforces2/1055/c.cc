#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef unsigned __int128 ull;
const static ull BASE = 233;

struct HashSeq{
    vector<ull> P, H;

    HashSeq(string& s){
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for(int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE;
        H.resize(n + 1);
        H[0] = 0;
        for(int i = 1; i <= n; i++)H[i] = H[i - 1] * BASE + s[i - 1]; 
    }

    ull query(int l, int r){
        return H[r] - H[l - 1] * P[r - l + 1];
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::string s, t1, t2;
    std::vector<int> pre1(n + 1), pre0(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i & 1) t1 += '0', t2 += '1';
        else t1 += '1', t2 += '0';
        s += (a[i] + '0');
        pre1[i + 1] = pre1[i] + (a[i] == 1);
        pre0[i + 1] = pre0[i] + (a[i] == 0);
    }
    HashSeq h1(s), h2(t1), h3(t2);
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        int ans = 0, len = r - l + 1;
        // std::cout << len << '\n';
        if (len % 3 == 0 && ((pre1[r] - pre1[l - 1]) % 3 == 0) && (pre0[r] - pre0[l - 1]) % 3 == 0) {
            ans = len / 3;
            if (h1.query(l, r) == h2.query(1, len) || 
                h1.query(l, r) == h3.query(1, len)) {
                    ans++;
                }
        } else {
            ans = -1;
        }
        std::cout << ans << '\n';
    }
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