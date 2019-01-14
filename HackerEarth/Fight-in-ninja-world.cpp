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

int t,n,a,b,ans,cnt,temp;
std::vector<vi> adj(100005);
bool visited[100005];
std::vector<int> node;

void dfs(int u, bool tim){
    if (tim) temp++;
    visited[u] = true;
    cnt++;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (!visited[v]){
            if (tim==1){
                dfs(v,0);
            }
            else{
                dfs(v,1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    int tc = 1;
    while(t--){
        node.clear();
        REP(i,adj.size()) adj[i].clear();
        RESET(visited,0);
        ans = 0;
        cin>>n;
        REP(i,n){
            cin>>a>>b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
            node.pb(a);
            node.pb(b);
        }
        REP(i,node.size()){
            int now = node[i];
            if (!visited[now]){
                temp = 0;
                cnt = 0;
                //cout<<i<<endl;
                dfs(now,0);
                //cout<<temp<<" "<<cnt<<endl;
                ans +=max(temp,cnt-temp);
            }
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
        tc++;
    }
}
