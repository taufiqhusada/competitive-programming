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

int n,a,b;
std::vector<vi> adj(200005);
int par[200005];
int dis[200005];

void dfs(int u, int p, int d){
    dis[u] = d;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            par[v] = u;
            dfs(v,u,d+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n-1){
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,0,0);
    set<pair<int,int> > s;
    REP(i,n){
        if (dis[i]>2) s.insert(mp(-dis[i],i));
    }
    int ans = 0;
    while(!s.empty()){
        int v = s.begin()->se;
        v = par[v];
        ans++;
        auto it  = s.find(mp(-dis[v],v));
        if (it!=s.end()) s.erase(it);
        for(auto child : adj[v]){
            auto it = s.find(mp(-dis[child],child));
            if (it!=s.end()) s.erase(it);
        }
    }
    cout<<ans<<endl;    
}
