// Codeforces Beta Round #80 (Div. 1 Only) : Prob  B

#include<bits/stdc++.h>
using namespace std;

int n,m;
std::vector<vector<int> > adj(105);
bool visit[105];
int cnt;

void dfs(int u){
    visit[u] = 1;
    for (int i = 0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        if (visit[v]==0){
            dfs(v);
        }
    }
    cnt++;
}

int main(){
    cin>>n>>m;
    int a,b;
    for (int i =0 ; i<m; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (n!=m){
        cout<<"NO"<<endl;
        return 0;
    }
    dfs(1);
    for (int i = 1; i<=n; ++i){
        if (visit[i]==0){
            isC=0;
            break;
        }
    }
    if (cnt==n) cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;
}
