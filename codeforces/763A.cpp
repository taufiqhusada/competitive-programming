#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back

typedef vector<int> vi;

int n,a,b;
std::vector<vi> adj(100005);
int c[100005];
int color;
bool valid;

void dfs(int p, int u){
    valid = valid && (c[u]==color);
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if(v!=p){
            dfs(u,v);
        }
    }
}

bool solve(int v){
    int ans = 1;
    REP(i,adj[v].size()){
        color = c[adj[v][i]];
        valid = true;
        dfs(v,adj[v][i]);
        ans  = ans && valid;
    }
    return ans;
}

int main(){
    cin>>n;
    REP(i,n-1){
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int first = -1;
    int second = -1;
    REP(i,n) cin>>c[i];
    REP(i,n){
        REP(j,adj[i].size()){
            if(c[adj[i][j]]!=c[i]){
                first = i;
                second = adj[i][j];
            }
        }
    }
    //cout<<first<<" "<<second<<endl;
    if(first==-1){
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
    }
    else{
        bool solve1 = solve(first);
        bool solve2 = solve(second);
        if(solve1){
            cout<<"YES"<<endl;
            cout<<first+1<<endl;
            return 0;
        }
        else if(solve2){
            cout<<"YES"<<endl;
            cout<<second+1<<endl;
            return 0;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}
