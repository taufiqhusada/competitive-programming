#include<bits/stdc++.h>
using namespace std;

int t;
int r, c;
char a[1005][1005];
int dist[1005][1005];


int x[] = {1,0,-1,0};
int y[] = {0,-1,0,1};

int main(){
    cin>>t;
    while(t--){
        cin>>r>>c;
        for (int i = 0; i<r; ++i){
            string s;
            cin>>s;
            for (int j = 0; j<c; ++j){
                a[i][j] = s[j];
            }
        }

        for (int i =0 ; i<r; ++i){
            for (int j = 0; j<c; ++j){
                dist[i][j] = 99999999;
            }
        }

        deque<pair<int, int>> deq;
        deq.push_front({0,0});
        dist[0][0] = 0;
        while(!deq.empty()){
            int ui = deq.front().first;
            int uj = deq.front().second;
            deq.pop_front();


            for (int k =0; k<4; ++k){
                int vi = ui + y[k];
                int vj = uj + x[k];
                // cout<<ui<<" "<<uj<<" "<<vi<<" "<<vj<<endl;
                if (vi >= r || vi < 0 || vj >= c|| vj<0) continue;
                int cost = 1;
                if (a[ui][uj] == a[vi][vj]){
                    cost = 0;
                }

                if (dist[vi][vj] > dist[ui][uj] + cost){
                    dist[vi][vj] = dist[ui][uj] + cost;
                    if (cost==1){
                        deq.push_back({vi,vj});
                    }
                    else{
                        deq.push_front({vi,vj});
                    }
                }
            }
        }

        cout<<dist[r-1][c-1]<<endl;
    }
}
