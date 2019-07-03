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

ll n,p,q,r,a[100005],maxi,mini,dp[100005][3],b[100005];

ll solve(int pos, int turn){
    if (pos>=n && turn<3) return -9999999999999;
    if (pos>=n) return 0;
    if (turn>2) return 0;
    if (dp[pos][turn]!=-1) return dp[pos][turn];

    ll &ret = dp[pos][turn];
    if (turn==0){
        return ret = max(solve(pos+1,turn), p*a[pos]+solve(pos,turn+1));
    }
    if (turn==1){
        return ret = max(solve(pos+1,turn), q*a[pos]+solve(pos,turn+1));
    }
    return ret = max(solve(pos+1,turn), r*a[pos]+solve(pos,turn+1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>q>>r;
    REP(i,n){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    if (p==q && q==r){
        if (p<0){
            cout<<3*p*b[0];
        }
        else cout<<3*p*b[n-1];
        return 0;
    }
    RESET(dp,-1);
    cout<<solve(0,0)<<endl;

}
