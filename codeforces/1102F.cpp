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

int allmask, n,m;
ll a[20][20005], dp[66666][20];

ll solve(int mask, int pos, ll k, int awal, int allmask){
    if (mask==allmask){
        ll mini = INF;
        REP(i,m-1){
            mini = min(mini, abs(a[pos][i]-a[awal][i+1]));
        }
        return mini = min(mini, k);
    }
    if (dp[mask][pos]!=-1) return dp[mask][pos];
    ll &ret = dp[mask][pos];
    ll ans = -1;
    REP(i,n){
        if (!(mask&(1<<i))){
            ll newk = INF;
            REP(j,m){
                newk = min(newk, abs(a[pos][j]-a[i][j]));
            }
            ans = max(ans, solve(mask|(1<<i), i, min(k,newk), awal,allmask));
        }
    }
    return ret = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n){
        REP(j,m) cin>>a[i][j];
    }
    int allmask = (1<<n)-1;
    ll res = -1;
    REP(i,n){
        RESET(dp,-1);
        res = max(res, solve((1<<i),i,INF,i,allmask));
    }
    cout<<res<<endl;
}
