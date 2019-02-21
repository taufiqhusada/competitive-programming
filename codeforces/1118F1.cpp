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
std::vector<vi> adj(300005);
int c[300005],r[300005],b[300005],red,blue,ans,v1,v2;

void dfs(int u, int par){
    if (c[u]==1) r[u]++;
    else if (c[u]==2) b[u]++;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=par){
            dfs(v,u);
            b[u]+=b[v];
            r[u]+=r[v];
            if (b[v]==blue && r[v]==0) ans++;
            else if (r[v]==red && b[v]==0) ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) {
        cin>>c[i];
        if (c[i]==1) red++;
        else if(c[i]==2) blue++;
    }
    REP(i,n-1){
        cin>>v1>>v2;
        v1--; v2--;
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    dfs(0,-1);
    cout<<ans<<endl;
}
