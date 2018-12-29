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
bool visit[200005];
int n,a,b;
vi res;

void dfs(int u){
    visit[u]= true;
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (visit[v]==false && v!=0){
            //cout<<u<<"-->>"<<v<<endl;
            dfs(v);
        }
    }
    res.pb(u);
}
int coba1,coba2;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;

    int akhir;
    FOR(i,1,n){
        cin>>a>>b;
        if(a==1 && coba1 == 0){
            coba1 = i;
        }
        else if (a==1){
            coba2 = i;
        }
        else adj[i].pb(a);
        if(b==1 && coba2 == 0){
            coba2 = i;
        }
        else if (b==1){
            coba1 = i;
        }
        else adj[i].pb(b);
    }
    //cout<<coba1<<" "<<coba2<<endl;
    if(adj[coba1][0]==coba2){
        adj[coba2][0] = 0;
    }
    else{
        adj[coba1][0]= 0;
    }
    dfs(1);
    for (int i = (int)res.size()-1; i>=0; --i){
        cout<<res[i]<<" ";
    }
}
