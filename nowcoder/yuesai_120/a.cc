#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto ch : s) mp[ch]++;
    int t = -1;
    for (auto [k, v] : mp) {
        if (t == -1) {
            t = v;
        } else {
            if (t != v - 1) {
                cout << "NO\n";
                return;
            }
            t = v;
        }
    }
    cout << "YES\n"; 
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}