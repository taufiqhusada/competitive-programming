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

ll sum,dp[55][2],a[55];
int n;

ll solve(int pos, bool token){
    if (pos>=n) return 0;
    if (dp[pos][token]!=-1) return dp[pos][token];
    ll &ret = dp[pos][token];
    if (token==false){
        return ret = min(solve(pos+1,1), a[pos]+solve(pos+1,0));
    }
    return ret = max(solve(pos+1,0)+a[pos], solve(pos+1, 1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) {
        cin>>a[i];
        sum+=a[i];
    }
    RESET(dp,-1);
    cout<<sum-solve(0,1)<<" "<<solve(0,1);
}
