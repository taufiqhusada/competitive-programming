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

int n,m,a,b,allmask;
int dis[20][20], e[20][20], Eall, E, D;
std::vector<vi> adj(20);
ll dp[20][105][1<<14];

ll solve(int u, int Eall, int mask){
    if (mask==allmask) return 0;
    if (Eall==0) return INF;
    if (dp[u][Eall][mask]!=-1) return dp[u][Eall][mask];
    ll ans = INF;
    REP(i, adj[u].size()){
        int v = adj[u][i];
        if (!(mask&(1<<v)) && e[u][v]<=Eall){
            ans = min(ans, dis[u][v] + solve(v,Eall-e[u][v],mask|(1<<v)));
            //cout<<u<<" ..."<<v<<": "<<ans<<endl;
        }
    }
    return dp[u][Eall][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>Eall;
    REP(i,m){
        cin>>a>>b>>D>>E;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        e[a][b] = E;
        e[b][a] = E;
        dis[a][b] = D;
        dis[b][a] = D;
    }
    RESET(dp,-1);
    allmask = (1<<n) -1;
    ll res = solve(0,Eall,1);
    if (res<INF) cout<<res<<endl;
    else cout<<-1<<endl;
}
