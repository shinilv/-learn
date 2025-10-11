#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int LOGN = 20;
typedef long long ll;

int n, m, q, ne[30], fa[N][LOGN + 2];
int a[N];
string s;

void lca_init()
{
    for(int i = n; i >= 0; i--)
        for(int j = 1; j <= LOGN; j++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int lca_query(int u, int v)
{
    int res = 0;
    for(int j = LOGN; j >= 0; j--)
        if(fa[u][j] <= v && fa[u][j] != 0)    
            u = fa[u][j], res += (1 << j);
    return res;
}
void solve()
{
    cin>>m>>n;
    cin>>s; s = "a" + s;
    for(int i = 0; i <= n; i++)
        a[i] = (s[i] - 'a' + 1);

    for(int j = 1; j <= m; j++)
        ne[j] = n + 1;

    for(int i = n; i >= 0; i--)
    {
        for(int j = 1; j <= m; j++)
            fa[i][0] = max(ne[j], fa[i][0]);
        if(i)
            ne[a[i]] = i;
    }
    lca_init();
    cin>>q;
    for(int i = 1; i <= q; i++)
    {
        int l, r;   cin>>l>>r;
        cout<<lca_query(l - 1, r) + 1<<'\n';
    } 
}

int main() {
    solve();
    return 0;
}