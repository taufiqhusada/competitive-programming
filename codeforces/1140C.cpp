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
ll a,b;
std::vector<pair<ll,ll> > v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n){
        cin>>a>>b;
        v.pb(mp(b,a));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll sum = v[0].se;
    pq.push(v[0].se);
    ll ans = sum*v[0].fi;
    FOR(i,1,n-1){
        if (pq.size()==k){
            sum-=pq.top();
            pq.pop();
        }
        pq.push(v[i].se);
        sum+=v[i].se;
        ans = max(ans,sum*v[i].fi);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
