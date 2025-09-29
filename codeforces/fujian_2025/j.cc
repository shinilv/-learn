#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        while (n < (1LL << 40)) {
            ans.push_back(n & -n);
            n += n & -n;
        }   
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }

    return 0;
}