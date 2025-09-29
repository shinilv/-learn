#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, vector<pair<int, string>>> mp[26];
    for (int i = 0; i < n; i++) {
        string a, b, c;
        int ti;
        cin >> a >> b >> ti >> c;
        mp[b[0] - 'A'][a].push_back({ti, c});
    }
    unordered_map<string, array<int, 2>> cnt, cnt2;
    for (int i = 0; i < 26; i++) {
        for (auto& [k, arr] : mp[i]) {
            sort(arr.begin(), arr.end());
            int time = 0;
            for (auto [ti, c] : arr) {
                if (c[0] == 'A') {
                    cnt[k][0]--, cnt[k][1] += time + ti;
                    break;
                } else if (c[0] == 'R') {
                    time += 20;
                } else {
                    cnt2[k][0]--, cnt2[k][1] += time + ti;
                    break;
                }
            }
        }
    }
    array<int, 2> tmp({0, 0});
    string ans;
    for (auto& [k, v] : cnt) {
        if (v < tmp) {
            ans = k;
            tmp = v;
        }
    } 
    // cout << ans << '\n';
    set<string> res;
    for (auto& [k, v] : cnt) {
        array<int, 2> t;
        t[0] = v[0] + cnt2[k][0], t[1] = v[1] + cnt2[k][1];
        if (t <= cnt[ans]) {
            res.insert(k);
        }
    }
    for (auto& [k, p] : cnt2) {
        if (p <= cnt[ans]) {
            res.insert(k);
        }
    }
    for (auto& x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}