//Helvetic Coding Contest 2016 online mirror (teams, unrated) : C2. Brain Network (medium)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bool visit[100005];
vector<vector<int> > adj(100005);
int dis[100005],n,m,a,b,maxNode;
int maxi = -1;


void dfs(int u, int d){
	visit[u] = 1;
	if (d>maxi){
        maxi = d;
        maxNode =u;
	}
	for (int i = 0; i <adj[u].size() ; ++i)
	{
		int v = adj[u][i];
		if (visit[v]==0){
			dfs(v,d+1);
		}
	}
}


int main(){
	cin>>n>>m;
	for (int i = 0; i<m; ++i){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1,0);
	memset(visit,0,sizeof(visit));
	maxi = -1;
	dfs(maxNode,0);
	cout<<maxi<<endl;
}
