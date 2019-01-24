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
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int k,c[1010];
ll f[1010][1010];
ll dp[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k;
    FOR(i,1,k) cin>>c[i];
    // precompute combination
    f[0][0] = 1;
    FOR(i,1,1005){
        f[i][0] = 1;
        FOR(j,1,1005){
            f[i][j] = (f[i-1][j] + f[i-1][j-1])%MOD;
        }
    }

    dp[0] = 1;
    ll sum = 0;
    FOR(i,1,k){
        dp[i] = (dp[i-1]*f[sum+c[i]-1][c[i]-1])%MOD;
        sum+=c[i];
        //cout<<dp[i]<<endl;
    }
    cout<<dp[k]<<endl;
}
