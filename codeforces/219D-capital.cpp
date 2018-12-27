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

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int n,a,b;
std::vector<vii> adj(200005);
int dp[200005];

void dfs(int u, int p){
    REP(i,adj[u].size()){
        int v = adj[u][i].fi;
        if (v!=p){
            dfs(v,u);
            dp[u]+=dp[v]+adj[u][i].se;
        }
    }
}

void solve(int u, int p){
    REP(i,adj[u].size()){
        int v = adj[u][i].fi;
        if (v!=p){
            if(adj[u][i].se==0){
                dp[v] = dp[u] +1;
            }
            else{
                dp[v] = dp[u]-1;
            }
            solve(v,u);
        }
    }
}


int main(){
    cin>>n;
    REP(i,n-1){
        cin>>a>>b;
        a--; b--;
        adj[a].pb(mp(b,0));
        adj[b].pb(mp(a,1));
    }
    dfs(0,-1);
    solve(0,-1);
    int ans = INF;
    REP(i,n){
        ans = min(dp[i],ans);
    }
    cout<<ans<<endl;
    REP(i,n){
        if (dp[i]==ans){
            cout<<i+1<<" ";
        }
    }

}
