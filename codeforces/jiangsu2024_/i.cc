#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N],b[N],c[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0)b[i]=b[i-1]+1;
        else b[i]=b[i-1]-1;
    }

    int fl=1;
    set<int> st;
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            vector<int> a0,a1;
            for(int j=fl+1;j<=i;j++){
                if(c[i]==0)a0.push_back(a[j]);
                else a1.push_back(a[j]);
            }
            fl=i;
            sort(a0.begin(),a0.end());
            sort(a1.begin(),a1.end(),greater<>());
            for(int i=0;i<n;i++){
                st.insert(a0[i]+a1[i]);
            }
        }
    }
}