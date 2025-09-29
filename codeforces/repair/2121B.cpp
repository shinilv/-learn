#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int f = 0;
        int cnt[26]{};
        for (auto x : s) cnt[x - 'a'] ++;
        for (int i = 1; i < n - 1; i++) {
            if (cnt[s[i] - 'a'] > 1) {
                cout << "YES\n";
                f = 1;
                break;
            }
        }
        if (!f) cout << "NO\n";
    }
}