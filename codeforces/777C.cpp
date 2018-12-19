#include<bits/stdc++.h>
using namespace std;

#define ll long long

int k,n,m,l,r;

int main(){
    cin>>n>>m;
    ll a[n+1][m+1], dp[n+1][m+1], ans[n+1];
    memset(a,0,sizeof(a)); memset(dp,0,sizeof(dp)); memset(ans,0,sizeof(ans));
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j<=m; ++j){
            cin>>a[i][j];
            if (a[i][j]>=a[i-1][j])dp[i][j] = 1+dp[i-1][j];
            else dp[i][j] = 1;
        }
    }
    for (int i = 1; i<=n; ++i){
        for (int j = 1; j<=m; ++j){
            ans[i] = max(ans[i],dp[i][j]);
        }
    }
    cin>>k;
    while(k--){
        cin>>l>>r;
        if (ans[r]>=r-l+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
