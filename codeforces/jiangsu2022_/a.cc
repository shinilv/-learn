#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<array<string, 2>> vec(n);
    int cnt = 0;
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
        mp[vec[i][0]].push_back(vec[i][1]);
    }
    for (auto [k, arr] : mp) {
        // cout << k << '\n';
        for (int i = 0; i <= (int)arr.size() - 5; i++) {
            // cout << i << '\n';
            set<string> se;
            for (int j = i; j < i + 5; j++) {
                // cout << j << '\n';
                se.insert(arr[j]);
            }
            if (se.size() == 5) {
                cout << "PENTA KILL!\n";
                return 0;
            }
        }
    }
    cout << "SAD:(\n";
}