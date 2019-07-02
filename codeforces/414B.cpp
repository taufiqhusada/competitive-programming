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

int n,k;
ll dp[2005][2005];
std::vector<vi> v(2005);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    FOR(i,1,n){
        FOR(j,1,sqrt(i)){
            if (i%j==0){
                v[i].pb(j);
                if (j != i/j) v[i].pb(i/j);
            }
        }
    }
    // pos angkaTerakhir
    FOR(i,1,n){
        dp[1][i] = 1;
    }
    FOR(pos,2,k){
        FOR(lastNum,1,n){
            REP(i,v[lastNum].size()) {
                dp[pos][lastNum] += dp[pos-1][v[lastNum][i]]%MOD;
                //cout<<dp[pos][lastNum]<<endl;
            };
        }
    }
    ll ans = 0;
    FOR(i,1,n){
        ans+=dp[k][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}
