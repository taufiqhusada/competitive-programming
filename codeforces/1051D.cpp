#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define MOD 998244353

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int n,k;
ll dp[1005][2015][4];

int get(int mask, int nmask){
    int cnt = __builtin_popcount(mask^nmask);
    if(cnt==0) return 0;
    if (cnt==1) {
        if(mask==0 || mask==3) return 1;
        return 0;
    }
    if (mask==0 || mask==3) return 1;
    return 2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    dp[0][1][0] = 1;
    dp[0][1][3] = 1;
    dp[0][2][1] = 1;
    dp[0][2][2] = 1;

    REP(i,n){
        REP(j,k+1){
            REP(mask,4){
                REP(nmask,4){
                    dp[i+1][j+get(mask,nmask)][nmask] += dp[i][j][mask];
                    while(dp[i+1][j+get(mask,nmask)][nmask]>=MOD){
                        dp[i+1][j+get(mask,nmask)][nmask]-=MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    REP(mask,4){
		ans+= dp[n-1][k][mask];
        while(ans>=MOD){
            ans-=MOD;
        }
    }
    cout<<ans<<endl;

}
