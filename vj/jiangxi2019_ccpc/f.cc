#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[26]{};
    for (auto x : s) cnt[x - 'a']++;
    int a = cnt[0] * cnt['v' - 'a'] * cnt['i' - 'a'] * cnt['n' - 'a'], b = n * n * n * n;
    int g = __gcd(a, b);
    cout << a / g << '/' << b / g << '\n';
    return 0;
}