#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,prime[100005],dig,dp[100005][20][5];
ll x;

int solve(int pos, int mask, int turn){
    if(turn==3){
        if (!mask)return 0;
        else return 1;
    }
    if (pos>=n) return 0;
    if (dp[pos][mask][turn]!=-1) return dp[pos][mask][turn];
    return dp[pos][mask][turn] = solve(pos+1,mask,turn)+solve(pos+1,mask&prime[pos],turn+1);

}

int main(){
    cin>>n;
    for (int i = 0; i<n; ++i){
        cin>>x;
        while(x>0){
            dig = x%10;
            if (dig==2) prime[i]|=(1<<0);
            else if (dig==3) prime[i]|=(1<<1);
            else if (dig==5) prime[i]|=(1<<2);
            else if (dig==7) prime[i]|=(1<<3);
            x/=10;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,15,0)<<endl;

}
