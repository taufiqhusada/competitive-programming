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

int t,n,m,dis[200005];
std::vector<vi> adj(200005);


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        int a,b;
        REP(i,200005) adj[i].clear();
        REP(i,m){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        REP(i,200005) dis[i]=INF;
        dis[1] = 0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            REP(i,adj[u].size()){
                int v = adj[u][i];
                if (dis[v]==INF){
                    dis[v] = dis[u]+1;
                    q.push(v);
                }
            }
        }
        std::vector<int> odd;
        std::vector<int> even;
        FOR(i,1,n){
            //cout<<dis[i]<<" ";
            if (dis[i]&1) odd.pb(i);
            else even.pb(i);
        }
        if (odd.size()<even.size()){
            cout<<odd.size()<<endl;
            for (auto i: odd) cout<<i<<" ";
            cout<<endl;
        }
        else{
            cout<<even.size()<<endl;
            for(auto i:even) cout<<i<<" ";
            cout<<endl;
        }
    }
}
