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

int n,x;
ll s[100005],a[100005],sum;
bool valid;
std::vector<vi> adj(10005);

void dfs(int u, int p){
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            if (s[v]==-1){
                ll mini = INF;
                REP(j,adj[v].size()){
                    if (s[adj[v][j]]<s[u]){
                        valid = false;
                        return;
                    }
                    mini = min(mini, s[adj[v][j]]);
                }
                s[v] = mini;
                //cout<<mini<<endl;
                if (s[v]==INF) s[v]=s[u];
                sum+= s[v] - s[u];
                dfs(v,u);
            }
            else{
                if (s[v]<s[u]){
                    valid = false;
                    return;
                }
                else{
                    sum += s[v]-s[u];
                    dfs(v,u);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    FOR(i,2,n){
        cin>>x;
        adj[x].pb(i);
    }
    FOR(i,1,n){
        cin>>s[i];
    }
    valid = true;
    dfs(1,1);
    if (valid) cout<<sum+s[1]<<endl;
    else cout<<-1<<endl;
}
