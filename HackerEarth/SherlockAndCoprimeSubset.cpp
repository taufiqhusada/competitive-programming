#include<bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long ll;

int t,n,a[55],dp[33333][55], allmask,jumDiv,x,cntset,maxp;
bool valid;
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<vector<int> > v(55);


int solve(int mask,int i){
    if(mask==allmask) return 0;
    if (i>=n) return 0;
    if (dp[mask][i]!=-1) return dp[mask][i];
    jumDiv = 0;
    valid = true;
    for (int m = 0; m<v[i].size(); ++m){
        if (!(mask & (1 << v[i][m]))){
            jumDiv++;
        }
        else{
            valid = false;
            break;
        }
    }
    if (valid){
        int newmask = mask;
        for (int j = 0; j<jumDiv; ++j){
            newmask|=(1<<v[i][j]);
            //cout<<tempList[j]<<endl;
            //cout<<newmask<<endl;
        }
        return dp[mask][i] = max(solve(newmask,i+1)+1,solve(mask,i+1));
    }
    return dp[mask][i] = solve(mask,i+i);
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 0; i<v.size(); ++i) v[i].clear();
        maxp = -1;
        for (int i = 0; i<n; ++i){
            cin>>a[i];
            for (int p = 0; p<15 && prime[p]<=a[i]; ++p){
                if (a[i]%prime[p]==0) {
                    v[i].pb(p);
                    maxp = max(maxp,p);
                }
            }
        }
        allmask = (1<<(maxp+1))-1;
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
}
