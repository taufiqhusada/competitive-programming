#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int t,n,a[25],allmask,dp[1111111][2];

solve(int mask, int turn){
    if (mask==0) return 0;
    if (dp[mask][turn]!=-1) return dp[mask][turn];
    if (turn==1){
        int index, val=INF;
        for (int i = 0; i<n; ++i){
            if (!(mask&(1<<i))){
                if (a[i]<val){
                    val = a[i];
                    index = i;
                }
            }
        }
        return dp[mask][turn] = val + solve(mask^(1<<index),0);
    }
    else{
        bool tinggal1 = true;
        int cnt = 0,index;
        for (int i = 0; i<n; ++i){
            if (mask&(1<<i)){
                index = i;
                cnt++;
            }
            if(cnt==2){
                tinggal1 = false;
                break;
            }
        }
        if(tinggal1){
            return dp[mask][turn] = a[index];
        }
        else{
            int ans = INF;
            for (int i = 0; i<n; ++i){
                for (int j = i+1; j<n; ++j){
                    if ((mask&(1<<i)) && (mask&(1<<j)) ){
                        ans = min(ans, max(a[i],a[j])+solve((mask^(1<<i))^(1<<j),1) );
                    }
                }
            }
            //cout<<ans<<endl;
            return dp[mask][turn] = ans;
        }
    }
}


int main(){
    cin>>t;
    while(t--){
        cin>>n;
        allmask =  (1<<n)-1;
        for (int i = 0; i<n; ++i) cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(allmask,0)<<endl;
    }
}
