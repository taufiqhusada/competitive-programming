// EZDIJKST - Easy Dijkstra Problem
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,v,e,a,b,c,asal,tujuan,x;

int main(){
	cin>>t;
	while(t--){
		cin>>v>>e;
		ll dist[v+1];
		ll w[v+1][v+1];
        memset(w,-1,sizeof(w));
		for (int i = 1; i <= v; ++i)
		{
			dist[i] = INT_MAX;
		}
		for (int i = 0; i < e; ++i)
		{
				cin>>a>>b>>c;
				w[a][b] = c;
		}
		cin>>asal>>tujuan;
		priority_queue<pair<int,int> > pq;
		dist[asal] = 0;
		pq.push(make_pair(-dist[asal],asal));
		while(!pq.empty()){
			x = pq.top().second;
			pq.pop();
			for (int i = 1; i<=v; i++){
				if (dist[i]>dist[x]+w[x][i] && w[x][i]!=-1){
					dist[i] = dist[x]+w[x][i];
					pq.push(make_pair(-dist[i],i));
				}
			}
		}
		if (dist[tujuan]<INT_MAX)
            cout<<dist[tujuan]<<endl;
        else cout<<"NO"<<endl;

	}



	return 0;

}
