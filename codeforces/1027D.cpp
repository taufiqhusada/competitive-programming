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

int n;
int c[200005],out[200005],x;
bool recstack[200005];
bool done[200005];
ll ans;
int mini;
bool vis[200005];
std::vector<vi> adj(200005);
std::vector<int> cycle;

void dfs(int u){
    vis[u] = true;
    recstack[u] = true;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (!vis[v]){
            dfs(v);
        }
        else if (recstack[v]){
            cycle.pb(v);
        }
    }
    recstack[u] = false;
}

void solve(int u, int awal){
    //cout<<u<<endl;
    mini = min(mini,c[u]);
    //cout<<u<<" "<<c[u]<<" "<<"min :"<<mini<<endl;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=awal && !done[v]){
            solve(v,awal);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    FOR(i,1,n) cin>>c[i];
    FOR(i,1,n){
        cin>>x;
        adj[i].pb(x);
        out[i]++;
    }
    FOR(i,1,n){
        if (!vis[i]){
            dfs(i);
        }
    }
    REP(i,cycle.size()){
        //cout<<cycle[i]<<endl;
        mini  = INF;
        solve(cycle[i],cycle[i]);
        ans+=ll(mini);
    }
    cout<<ans<<endl;
}
