#include <bits/stdc++.h>
using namespace std;
#define int __int128

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void write(int x){
    if (x > 9)
        write(x / 10ll);
    putchar(x % 10 + '0');
}

int c;

int func(vector<int>& a, int x) {
    int n = a.size();
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i & 1) res -= x / a[i];
        else res += x / a[i];
    }
    return res;
}

vector<int> a, b; 

int check(int x) {
    return x - func(a, x) - c;
}

void solve() {
    int n = read();
    int l = 2025, r = 2e18;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid) >= n) r = mid;
        else l = mid + 1;
    }
    write(l);
    cout << '\n';
}

signed main() {
    int t1 = 4, t2 = 100;
    while (t1 <= 1e18) {
        a.push_back(t1);
        t1 *= 100;
    }
    while (t2 <= 1e18) {
        a.push_back(t2);
        t2 *= 100;
    }
    sort(a.begin(), a.end());

    c = 2024 - func(a, 2024);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}