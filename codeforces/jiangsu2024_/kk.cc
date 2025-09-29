#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    map<int,int> mp;
    cin>>n;
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        mp[in]++;
    }
    int mi=0;
    for(auto [x,y]:mp){
        if(x>mi)mi=x;
    }
    if(mp[mi]%2==0){
        cout<<"Bob";
    }else{
        cout<<"Alice";
    }
    return 0;
}