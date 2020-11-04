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

int t, n, m;

int x;
int p[100005];
int h[100005];
int cnt[100005];
int g[100005];
std::vector<vi> adj(100005);
int a,b;
bool valid;

void dfs(int u, int par){
    cnt[u] = p[u];
    int sumGood = 0;
    for (auto v: adj[u]){
        if (v!=par){
            dfs(v, u);
            cnt[u] += cnt[v];
            sumGood += g[v];
        }
    }
    if ((cnt[u] + h[u]) % 2 !=0){
        valid = false;
    }
    g[u] = (cnt[u] + h[u]) /2;
    if (!(g[u] >= 0 && g[u] <= cnt[u])){
        valid = false;
    }
    if (sumGood > g[u]){
        valid = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;

        for (int i = 0; i<n; ++i){
            cin>>p[i];
        }
        for (int i = 0; i<n; ++i){
            cin>>h[i];
        }

        for (int i = 0; i<n-1; ++i){
            cin>>a>>b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        valid = true;
        dfs(0,0);
        if (valid){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

        for (int i = 0; i<n; ++i){
            adj[i].clear();
        }
        RESET(g, 0);
        RESET(cnt, 0);
    }
}
