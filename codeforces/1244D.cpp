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

int n,m;
ll c[100005][4];
int a,b;
std::vector<vi> adj(100005);
int anscol[100005];

ll ans;

void dfs(int v, int p, int col2, int col1){
    int now;
    REP(i,3){
        if (i!=col2 || i!=col1){
            ans+= c[v][i];
            now = i;
            break;
        }
    }
    REP(i,adj[v].size()){
        int u = adj[v][i];
        if (u!=p){
            // cout<<u<<" "<<p<<endl;
            dfs(u,v,col1,now);
        }
    }
}


void dfs2(int v, int p, int col2, int col1){
    int now;
    REP(i,3){
        if (i!=col2 || i!=col1){
            ans+= c[v][i];
            now = i;
            break;
        }
    }
    anscol[v] = now+1;
    REP(i,adj[v].size()){
        int u = adj[v][i];
        if (u!=p){
            // cout<<u<<" "<<p<<endl;
            dfs2(u,v,col1,now);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,3){
        REP(j,n) cin>>c[j][i];
    }
    REP(i,n-1){
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ujung;
    int anak,anak2;
    REP(i,n){
        if (adj[i].size()==1){
            ujung  = i;
            anak = adj[i][0];
            REP(j,adj[anak].size()){
                if (adj[anak][j]!=ujung)anak2 = adj[anak][j];

            }
        }
        if (adj[i].size()>2){
            cout<<-1<<endl;
            return 0;
        }
    }
    // cout<<ujung<<anak<<anak2<<endl;
    int ansi,ansj;
    ll mini = 9999999999999;
    REP(i,3){
        REP(j,3){
            if (i==j) continue;
            ans = 0;
            ans += c[ujung][i] + c[anak][j];
            dfs(anak2,anak,i,j);
            // cout<<?i<<" "<<j<<" "<<ans<<endl;
            if (ans<mini){
                ansi = i;
                ansj = j;
                mini = ans;
            }
        }
    }
    cout<<mini<<endl;
    anscol[ujung] = ansi+1;
    anscol[anak] = ansj+1;
    dfs2(anak2,anak,ansi,ansj);
    REP(i,n){
        cout<<anscol[i]<<" ";
    }
}
