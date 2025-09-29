#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
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

int main() {
    string s;
    cin >> s;
    HashSeq hs(s);
    int n = s.size();
    int cnt = 0;
    ull t = hs.query(1, 1000);
    for (int i = 1; i + 1000 <= n; i++) {
        if (t == hs.query(i, i + 1000 - 1)) {
            cnt++;
            i += 1000;
        }
    }
    if (cnt < 100) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}