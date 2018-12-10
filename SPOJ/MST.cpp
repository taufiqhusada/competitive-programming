#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t,v,e,a,b,c,asal,tujuan,x;
ll temp;

int main(){
		cin>>v>>e;
		bool visit[v+1];
		memset(visit,0,sizeof(visit));
		int dist[v+1];
		int w[v+1][v+1];
        memset(w,-1,sizeof(w));
		for (int i = 1; i <= v; ++i)
		{
			dist[i] = INT_MAX;
		}
		for (int i = 0; i < e; ++i)
		{
				cin>>a>>b>>c;
				w[a][b] = c;
				w[b][a] = c;
		}
		priority_queue<pair<int,int> > pq;
		ll res = 0;
		dist[1] = 0;
		pq.push(make_pair(-dist[1],1));
		while(!pq.empty()){
			x = pq.top().second;
			temp = pq.top().first;
			pq.pop();
			if (visit[x]==0){
                    visit[x]=1;
                    res+=-temp;
                    for (int i = 1; i<=v; i++){
                        if (dist[i]>w[x][i] && w[x][i]!=-1 && x!=i && visit[i]==0){

                            dist[i] = w[x][i];
                            pq.push(make_pair(-dist[i],i));
                        }
                    }
			}
		}

		cout<<res<<endl;

	return 0;
