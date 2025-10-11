#include <bits/stdc++.h>

typedef unsigned __int128 ull;
const static ull BASE = 233;

struct HashSeq{
    std::vector<ull> P, H;

    HashSeq(std::string& s){
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

signed main() {
    int n;
    std::cin >> n;
    std::map<ull, int> mp;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        reverse(s.begin(), s.end());
        HashSeq hs(s);
        for (int j = 1; j <= s.size(); j++) {
            ++mp[hs.query(1, j)];
        }
    }
    std::cout << mp.size() << '\n';
    return 0;
} 