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

std::vector<vi> adj(200005),child(200005);
std::vector<ll> v;
int n,x,y;
ll a[200005];
ll dp[200005],sum[200005];

bool cmp(ll a, ll b){
    return a>b;
}

void dfs(int u, int p){
    sum[u]+=a[u];
    dp[u] = -999999999999;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            child[u].pb(v);
            dfs(v,u);
            sum[u]+=sum[v];
            dp[u] = max(dp[u],dp[v]);
        }
    }
    dp[u] = max(dp[u],sum[u]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n-1){
        cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0,-1);
    ll ans = -999999999999;
    REP(i,n){
        if (child[i].size()>=2){
            REP(j,child[i].size()){
                v.pb(dp[child[i][j]]);
            }
            sort(v.begin(),v.end(),cmp);
            ans = max(ans, v[0]+v[1]);
            v.clear();
        }
    }
    if (ans>-999999999999) cout<<ans<<endl;
    else cout<<"Impossible"<<endl;
}
