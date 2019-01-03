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

int n,m;
int a[1005][1005];
ll dp[4][1005][1005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin>>a[i][j];
        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
            dp[0][i][j] = a[i][j] + max(dp[0][i-1][j], dp[0][i][j-1]);
        }
    }
    FORD(i,n,1){
        FORD(j,m,1){
            dp[1][i][j] = a[i][j] + max(dp[1][i+1][j], dp[1][i][j+1]);
        }
    }
    FORD(i,n,1){
        FOR(j,1,m){
            dp[2][i][j] = a[i][j] + max(dp[2][i+1][j], dp[2][i][j-1]);
        }
    }
    FOR(i,1,n){
        FORD(j,m,1){
            dp[3][i][j] = a[i][j] + max(dp[3][i][j+1], dp[3][i-1][j]);
        }
    }
    ll ans = -1;
    FOR(i,2,n-1){
        FOR(j,2,m-1){
            ans = max(ans,dp[0][i-1][j]+dp[1][i+1][j]+dp[2][i][j-1]+dp[3][i][j+1]);
            ans = max(ans,dp[0][i][j-1]+dp[1][i][j+1]+dp[2][i+1][j]+dp[3][i-1][j]);
        }
    }
    cout<<ans<<endl;
}
