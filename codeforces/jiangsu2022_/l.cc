#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[0]) {
            cout << "0\n";
            return 0;
        }
    }
    cout << s.size() - 1 << '\n';
}