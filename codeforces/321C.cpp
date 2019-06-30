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

bool cat[100005];
std::vector<vi> adj(100005);
int deg[100005];
int a,b;
int n,m;
ll cnt;

void dfs(int u, int p, int now){
    //cout<<u<<" from "<<p<<" = "<<now<<endl;
    if (now>m){
        return;
    }
    if (deg[u]==1 && u!=1){
        cnt++;
        return;
    }
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            if (cat[u]==1 && cat[v]==1) dfs(v,u,now+1);
            else if (cat[v]==1) dfs(v,u,1);
            else dfs(v,u,0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n){
        cin>>a;
        cat[i+1]=a;
    }
    REP(i,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    if (cat[1]==0)dfs(1,1,0);
    else dfs(1,1,1);
    cout<<cnt<<endl;
}
