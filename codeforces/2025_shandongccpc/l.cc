#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    string s = "OBAFGKM";
    while (t--) {
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "same";
        } else {
            int p1, p2;
            for (int i = 0; i < s.size(); i++) {
                if (a[0] == s[i]) {
                    a[0] = '0' + i;
                }
                if (b[0] == s[i]) {
                    b[0] = '0' + i;
                }
            }
            if (a < b) {
                cout << "hotter";
            } else {
                cout << "cooler";
            }
        }
        cout << endl;
    }
}