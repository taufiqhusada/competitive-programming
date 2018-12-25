#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

int t,k,a,b,n;
ll dp[100005], presum[100005];

int main(){
    cin>>n>>k;
    for (int i = 1; i<k; ++i){
        dp[i] = 1;
        presum[i]= (dp[i]+presum[i-1])%MOD;
    }
    dp[k] = 2;
    presum[k] = dp[k]+presum[k-1];
    for (int i = k+1; i<=100000; ++i){
        dp[i] = (dp[i-1]+dp[i-k])%MOD;
        presum[i]=(dp[i]+presum[i-1])%MOD;
    }
    while(n--){
        cin>>a>>b;
        ll ans = (presum[b]-presum[a-1])%MOD;
        if (ans<0) cout<<ans+MOD<<endl;
        else cout<<ans<<endl;
    }
}
