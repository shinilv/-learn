#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 2; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    return 0;
}