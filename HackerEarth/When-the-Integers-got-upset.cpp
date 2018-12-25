#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef long long ll;

int t,n,allmask;
int a[20], p[20];
ll dp[66666][20][20];

ll solve(int mask, int pos1, int pos2){
    ll ans = INF;
    if (mask==allmask) return 0;
    if (dp[mask][pos1][pos2]!=-1) return dp[mask][pos1][pos2];
    if (pos1==0){
        for (int i = 1; i<=n; ++i){
            ans = min(ans,solve(mask|(1<<i),i,0));
        }
        return dp[mask][pos1][pos2] = ans;
    }
    if (pos2==0){
        for (int i = 1; i<=n; ++i){
            if (!(mask&(1<<i))){
                ans = min(ans,solve(mask|(1<<i),pos1,i));
            }
        }
        return dp[mask][pos1][pos2] = ans;
    }
    int posp = __builtin_popcount(mask);
    for (int i = 1; i<=n; ++i){
        if (!(mask&(1<<i))){
            ans = min(ans,(a[pos1]^a[pos2]^a[i])*p[posp]+solve(mask|(1<<i),pos2,i));
        }
    }
    return dp[mask][pos1][pos2] = ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 1; i<=n; ++i){
            cin>>a[i];
        }
        for (int i = 1; i<=n; ++i){
            cin>>p[i];
        }
        allmask = (1<<(n+1)) - 1;
        memset(dp,-1,sizeof(dp));
        cout<<solve(1, 0, 0)<<endl;;
    }
}
