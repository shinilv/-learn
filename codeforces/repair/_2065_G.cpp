#include <bits/stdc++.h>
#define int long long


const int PRIME_N = 1000010;
int st[PRIME_N];
int primes[PRIME_N];
int cnt;
void fun()
{
    for (int i = 2; i < PRIME_N; i++)
    {
        if (!st[i])
        {
            st[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; i * primes[j] < PRIME_N; j++)
        {
            st[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                break;
        }
    }
}



void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp1, mp2;
    std::vector<std::array<int, 2>> vec;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int j = a[i];
        std::vector<int> ans;
        int c = 0;
        while(j > 1) {
            int p = st[j];
            while(j % p == 0) {
                c++;
                j /= p;
                ans.push_back(p);
            }
        }
        if (j > 1) {
            c++;
            ans.push_back(j);
        }
        if (c == 1) {
            mp1[a[i]]++;
            cnt++;
        } else if (c == 2) {
            mp2[a[i]]++;
            vec.push_back({ans[0], ans[1]});
        }
    }
    int ans = cnt * (cnt - 1) / 2;
    for (auto [k, v] : mp1) {
        ans = ans - v * (v - 1) / 2;
    }
    for (auto [k, v] : mp2) {
        ans = ans + v * (v - 1) / 2;
    }
    ans += vec.size();
    for (auto [a, b] : vec) {
        ans += mp1[a];
        if (a != b) {
            ans += mp1[b];
        }
    }
    std::cout << ans << '\n';
    
}

signed main() {
    fun();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}