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

int n, deg[200005], col[200005], maxi, a,b;
std::vector<vi> adj(200005);

void dfs(int u, int p){
    int colnow = 1;

    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            //cout<<v<<" "<<colnow<<endl;
            while(colnow == col[p] || colnow == col[u]) {
                colnow++;
            }
            col[v] =  colnow++;
            //cout<<"awal: "<<colnow<<endl;
            dfs(v,u);
            //cout<<"akhir: "<<colnow<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n-1){
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
        maxi = max(max(deg[a],deg[b]),maxi);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    col[1] = 1;
    dfs(1,1);
    cout<<maxi+1<<endl;
    FOR(i,1,n){
        cout<<col[i]<<" ";
    }
}
