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

ll solve(ll k, ll cnt){
    return cnt*(2+(cnt-1)*k)/2;
}

ll n;
std::vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (ll i = 1; i*i<=n; ++i){
        if(n%i==0){
        v.pb(solve(i,n/i));
        if(n>i*i)v.pb(solve(n/i,i));
    }
    }
    sort(v.begin(),v.end());
    REP(i,v.size())cout<<v[i]<<" ";
}
