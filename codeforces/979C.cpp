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

ll n,a,b,x,y,sz[300005];
bool ceksub[300005];
std::vector<vi> adj(300005);

void dfs(int u,int p){
    sz[u] = 1;
    if (u==x) ceksub[u] = true;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            dfs(v,u);
            sz[u]+=sz[v];
            ceksub[u]|=ceksub[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    REP(i,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(y,y);
    ll jum = 0;
    REP(i,adj[y].size()){
        int temp = adj[y][i];
        if(ceksub[temp]){
            jum+=sz[temp];
            break;
        }
    }
    cout<<1LL*n*(n-1)-sz[x]*(sz[y]-jum);
}
