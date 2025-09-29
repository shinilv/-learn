#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 2e3;
int qui(int a, int b, int MOD = MOD)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return res;
}

int fac[N], inv_fac[N];

void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv_fac[N - 1] = qui(fac[N - 1], MOD - 2);
    for (int i = N - 1; i > 0; i--)
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
}

int comb(int a, int b)
{
    return fac[a] * inv_fac[b] % MOD * inv_fac[a - b] % MOD;
}

int comb1(int a, int b) {
    return inv_fac[a] * fac[b] % MOD * fac[a - b] % MOD;
} 

void solve() {
    int n, m;
    cin >> n >> m;
    if (m <= 2) {
        cout << "0\n";
        return;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = i + j;
            int t = n - k + 1;
            if (t >= m - 2) {
                cout << i << ' ' << j << '\n';
                ans = (ans + comb(t, m - 2)) % MOD;
            }
        }
    }

    int ans1 = comb(n, m), ans2 = comb1(n, m);
    int t = (((ans1 - ans + MOD) % MOD) * ans2) % MOD;
    cout << t << '\n';

}
signed main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}