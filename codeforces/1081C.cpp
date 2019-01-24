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

int n,m,k;
ll dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    dp[1][0] = m;
    FOR(i,1,n){
        REP(j,k+1){
            if (i==1 && j==0) continue;
            dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
            dp[i][j] = (dp[i][j]+(dp[i-1][j-1]*(1LL*(m-1)))%MOD)%MOD;
        }
    }
    cout<<dp[n][k]<<endl;
}
