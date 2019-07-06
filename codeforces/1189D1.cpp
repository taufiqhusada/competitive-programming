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

int n,b,a;
std::vector<vi> adj(100005);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ok = true;
    FOR(i,1,n){
        if (adj[i].size()==2) ok = false;
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
