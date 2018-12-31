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
std::vector<vi> adj(100005);
int prime[] = {2,3,5,7,11,13,17,19};
int pembagi[25],deg[100005];
ll dp[100005][1<<8];

ll dfs(int par, int u,int g){
    if (dp[u][g]!=-1) return dp[u][g];
    ll ret = 0;
    bool leaf = true;
    FOR(d,1,m){
        ll ans = 1;
        int newgcd = g&pembagi[d];
        REP(i, adj[u].size()){
            int v = adj[u][i];
            if (v!=par){
                ans= (ans*dfs(u,v,newgcd)%MOD)%MOD;
                leaf = false;
            }
        }
        ret +=ans;
        ret = ret%MOD;
    }
    if (!leaf)return dp[u][g] = ret%MOD;

    // if leave
    ret = 0;
    FOR(i,1,m){
        int cek = pembagi[i]&g;
        if (cek==0) ret+=1;
    }
    //cout<<ret<<endl;
    return dp[u][g] = ret%MOD;
    //cout<<ret<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n-1){
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
    }
    FOR(i,1,m){
        REP(p,8){
            if(i%prime[p]==0){
                pembagi[i] |= (1<<p);
            }
        }
    }
    RESET(dp,-1);
    cout<<dfs(1,1,255)<<endl;

}
