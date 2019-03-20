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

int n,m,a,b;
int deg[200005],maxdeg,maxnode,visited[200005];
std::vector<vi> adj(200005);

void bfs(int s) {
	visited[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : adj[v]) {
			if (visited[to]) continue;
			cout<<to<<" "<<v<<endl;
			visited[to] = 1;
			q.push(to);
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    maxnode = 1;
    maxdeg = -1;
    REP(i,m){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
        if (deg[a]>maxdeg){
            maxdeg = deg[a];
            maxnode = a;
        }
        if (deg[b]>maxdeg){
            maxdeg = deg[b];
            maxnode = b;
        }
    }
    bfs(maxnode);
}
