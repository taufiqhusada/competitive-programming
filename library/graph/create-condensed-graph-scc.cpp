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

const int maxN = 100005;

int n,m;
int a,b;
std::vector<vi> adj(maxN);
std::vector<vi> adjR(maxN);
bool vis[maxN];
stack<int> s;

int who[maxN];      // representative node for each node
std::vector<vi> adjCondensed(maxN);

void dfs1(int u){
    vis[u] = true;
    for (auto v: adj[u]){
        if (!vis[v]){
            dfs1(v);
        }
    }
    s.push(u);
}

void dfs2(int u, int rep){
    vis[u] = true;
    who[u] = rep;
    for (auto v: adjR[u]){
        if (!vis[v]){
            dfs2(v, rep);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i = 0; i<m; ++i){
        cin>>a>>b;
        adj[a].pb(b);
        adjR[b].pb(a);
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i<n; ++i){
        if (!vis[i]){
            dfs1(i);
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i<n; ++i){
        int u = s.top();
        s.pop();
        if (!vis[u]){
            dfs2(u, u);
        }
    }

    for (int i = 0; i<n; ++i){
        cout<<i<<" "<<who[i]<<endl;
    }

    // create condensed graph
    for (int i = 0; i<n; ++i){
        for (int v: adj[i]){
            if (who[i] != who[v]){
                adjCondensed[who[i]].pb(who[v]);
            }
        }
    }
}
