#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    cnt[s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
        string s1 = s.substr(i);
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2) {
            cout << "HE\n";
            return;
        }
        cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] > 1) {
            break;
        }
    }
    cout << "NaN\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}