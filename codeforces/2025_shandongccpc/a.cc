#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> st(n + 1);
    map<int, vector<array<int, 2>>, greater<int>> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back({b, i + 1});
    }
    queue<int> q;
    for (auto& [k, arr] : mp) {
        sort(arr.begin(), arr.end(), greater<array<int, 2>>());
        int t = q.size();
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size() - 1 || arr[i][0] != arr[i + 1][0]) {
                if (arr[i][0] >= t) {
                    for (int j = i; j >= i - cnt; j--) {
                        q.push(arr[j][1]);
                    }
                    cnt = 0;
                } else {
                    if (cnt + arr[i][0] + 1 >= t) {
                        while (arr[i][0] < t) {
                            q.pop();
                            t--;
                        }
                        for (int j = i; j >= i - cnt; j--) {
                            q.push(arr[j][1]);
                        }
                        cnt = 0;
                    } else {
                        cnt++;
                    }
                }
            } else {
                cnt++;
            }
        }
    }
    cout << q.size() << '\n';
    while (q.size()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    } 
    return 0;
}