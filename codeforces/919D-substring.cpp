#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));

int n,m,a,b;
vector<vi> adj(300005);
int rail;
int dp[300005][30];
int deg[300005];
string s;

int main(){
    cin>>n>>m;
    cin>>s;
    REP(i,m){
        cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        deg[b]++;
    }
    int ans = -1;
    queue<int> q;
    REP(i,n){
        if (deg[i]==0) {
            q.push(i);
            rail++;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        dp[u][s[u]-'a']++;
        REP(i,adj[u].size()){
            int v = adj[u][i];
            deg[v]--;
            REP(j,26){
                dp[v][j] = max(dp[v][j],dp[u][j]);
            }
            if(deg[v]==0){
                q.push(v);
                rail++;
            }
        }
        REP(i,26){
            ans = max(ans,dp[u][i]);
        }
    }
    //cout<<rail<<endl;
    if(rail!=n)cout<<-1<<endl;
    else cout<<ans<<endl;

}
