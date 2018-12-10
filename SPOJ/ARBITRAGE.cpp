// SPOJ: ARBITRAG - Arbitrage

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,k,x,y;
string s,s1,s2;
double val;


int main(){
	bool yes = true;
	int c = 1;
	while(yes==true){
		cin>>n;
		if (n==0){
			yes= false;
		}
		else{
			double dist[n][n];
			memset(dist,0,sizeof(dist));
			map<string,int> m;
			int pos = 0;
			for (int i = 0; i<n; i++){
				cin>>s;
				if (m.find(s)==m.end()){
					m.insert(make_pair(s,pos));
					pos++;
				}
			}

            cin>>k;
            for (int i = 0; i < k; ++i)
            {
                cin>>s1>>val>>s2;
                x = (int)m[s1];
                y = (int)m[s2];
                dist[x][y] = val;
            }
            for (int k=0 ; k<n; k++ ){
            	for (int i=0; i<n; i++){
            		for(int j=0; j<n; j++){
            			dist[i][j] = max(dist[i][j],dist[i][k]*dist[k][j]);
            		}
            	}
            }
            bool arb = false;
            for (int i=0; i<n; i++){
                if (dist[i][i]>1)	arb= true;
            }
            if(arb) cout<<"Case "<<c<<":"<<" Yes"<<endl;
            else cout<<"Case "<<c<<":"<<" No"<<endl;
            c++;
		}
	}


	return 0;

}
