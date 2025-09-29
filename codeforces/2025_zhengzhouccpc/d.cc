#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    cin >> s;
    int x = stoi(s);
    int t = 0;
    for (auto x : s) {
        t += (x - '0');
    }
    int a = sqrt(x), b = sqrt(t);
    if (a * a == x && b * b == t) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}