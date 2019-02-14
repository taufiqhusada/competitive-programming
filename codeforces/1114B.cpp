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

int n,m,k;
ll x;
std::vector<pair<ll,int> > v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    REP(i,n){
        cin>>x;
        v.pb(mp(x,i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    std::vector<int> pos;
    ll sum = 0;
    REP(i,m*k){
        sum+=v[i].fi;
        pos.pb(v[i].se+1);
    }
    sort(pos.begin(),pos.end());
    cout<<sum<<endl;
    REP(i,k-1) cout<<pos[m*(i+1)-1]<<" ";
    cout<<endl;
}
