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

int n,m,a,b;
bool vis[150005];
ll node,edge,deg[150005];
std::vector<vi> adj(150005);

void dfs(int u, int p){
    vis[u]=true;
    node++;
    edge+=deg[u];
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p && !vis[v]){
            dfs(v,u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,m){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    REP(i,n){
        if (!vis[i+1]){
            node = 0;
            edge = 0;
            dfs(i+1,i+1);
            //cout<<edge<<" "<<node<<endl;
            if (edge!=(node*(node-1))){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}
