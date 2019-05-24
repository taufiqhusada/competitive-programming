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

int n;
ll a[200005], b[200005], val[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    sort(b,b+n);
    ll ans = 0;
    REP(i,n){
        val[i] = (i+1)*1ll*(n-i)*a[i];
    }
    sort(val,val+n);
    reverse(val,val+n);
    REP(i,n){
        ans = (ans + (val[i]% MOD * 1ll *   b[i]) % MOD) % MOD;
    }
    cout<<ans<<endl;

}
