#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    double ans = 0;
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        if (a[i].back() < '5') {
            ans -= (double)(a[i].back() - '0') / 1000;
        } else {
            ans += double('9' - a[i].back() + 1) / 1000;
        }
    }
    printf("%.3f", ans);
    return 0;
}