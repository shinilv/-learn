#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
ll m,n,k,ans,a,b,cnt,c,d,l,r; 
ll a1,a2,a3;
const int mod = 998244353;
string s1;
 
void solve() { 	
	cin >> n >> k;ans = 0;
	vector<int> x(n + 1);
	for(int i = 1;i <= n;i ++){
		cin >> x[i];
	}
//	sort(x.begin() + 1,x.begin() + 1 + n);
	if(k & 1) k = min(k,31ll);
	else k = min(k,30ll);
	for(int i = 1;i <= k;i ++){
		int p = 0;
		vector<int> y(n + 1,0);
		for(int j = 1;j <= n;j ++){
			y[x[j]] ++;
		}
		for(int j = 0;;j ++){
			if(!y[j]){
				p = j;
				break;
			}
		}
		for(int j = 1;j <= n;j ++){
			if(x[j] > p) x[j] = p;
			else if(x[j] <= p && y[x[j]] > 1){
				x[j] = p;
			}
		}
//		for(int i = 1;i <= n;i ++){
//			cout << x[i] << " "; 
//		}
//		cout << endl;
	}
	for(int i = 1;i <= n;i ++){
		ans += x[i];
	}
	cout << ans << endl;
	
}
int main() {
	int t; 
//    int t = 1;
    IOS;
     cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}