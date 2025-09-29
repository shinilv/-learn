#include <bits/stdc++.h>
using namespace std;

int ho[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

 int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int k = 0; k < 26; k++) {
        int cnt = 0;
        for (auto ch : s) {
            ch = ch - 'A';
            cnt += ho[(ch + k) % 26];
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
 }