#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define INF 1e9
#define vi vector<int>
#define MOD 998244353

typedef long long ll;
vector<vi> adj(300005);
ll n,m,t,a,b;
bool visit[300005], isCycle;
bool dis[300005];
ll lvl1,lvl2;
ll ans;

void dfs(ll u,bool d){
    dis[u] = d;
    if(d==1) lvl1++;
    else lvl2++;
    visit[u] = true;
    for (int i = 0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if (visit[v]==false){
            dfs(v,!d);
        }
        else{
            if (dis[u]==dis[v]){
                isCycle = true;
                break;
            }
        }
    }
}

ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        ans = 1;
        isCycle = false;
        cin>>n>>m;
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        adj.clear();
        for (int i = 0; i<m; ++i){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for (int i = 1; i<=n; ++i){
            lvl1 = 0; lvl2 = 0;
            isCycle = false;
            if (visit[i]) continue;
            else dfs(i,0);
            if(!isCycle) {
                ans *= (modpow(2,lvl1,MOD) + modpow(2,lvl2,MOD));
                ans = ans%MOD;
            }
            else{
                cout<<0<<endl;
                break;
            }
        }
        if (!isCycle)cout<<ans%MOD<<endl;
    }

}
