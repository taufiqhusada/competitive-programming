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

std::vector<vi> adj(200005);
bool ok;
int n,x,p[200005];
ll a[200005], s[200005];

void dfs(int u, int par, bool ganjil){
    if (u!=1){
        if (ganjil){
            if (s[u]<s[par]){
                //cout<<s[u]<<" <- "<<s[par]<<endl;
                ok =false;
                return;
            }
            a[u] = s[u]-s[par];

        }
        else{
            if (adj[u].size()==0){
                a[u] = 0;
                return;
            }
            ll mini =  INF;
            REP(i,adj[u].size()){
                int v = adj[u][i];
                if (v!=par){
                    mini = min(mini,s[v]);
                }
            }
            a[u] = mini - s[par];
            if (a[u]<0){
                ok = false;
                return;
            }
            s[u] = s[par]+a[u];
        }
    }
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=par){
            if (ganjil) dfs(v,u,0);
            else dfs(v,u,1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    FOR(i,2,n){
        cin>>x;
        adj[x].pb(i);
        p[i] = x;
    }
    REP(i,n){
        cin>>s[i+1];
    }
    a[1] = s[1];
    ok = true;
    dfs(1,1,1);
    if (!ok){
        cout<<-1<<endl;
        return 0;
    }
    ll sum = 0;
    REP(i,n){
        //cout<<i+1<<": "<<a[i+1]<<" "<<endl;
        sum+= a[i+1];
    }
    cout<<sum<<endl;
}
