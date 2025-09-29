#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cnt(26, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            cnt[s[j] - 'a'][j]++;
        }
        if (n == 1) {
            cout << s << endl;
            return;
        }
    }
    string ans;
    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            cnt[s[j] - 'a'][j]--;
            if (i == n - 2) {
                for (int k = 0; k < 26; k++) {
                    if (cnt[k][j]) {
                        ans += ('a' + k);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}