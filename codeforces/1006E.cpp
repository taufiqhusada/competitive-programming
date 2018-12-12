// Codeforces Round #498 (Div. 3) : E. Military Problem

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int n,q;
vector<vector<int> > adj(200005);
vector<int> res;
int pos[200005];
int cnt;

void dfs(int u){
    pos[u] = cnt;
    cnt++;
    res.pb(u);
    for (int i = 0; i<adj[u].size(); ++i){
        int v = adj[u][i];
        dfs(v);
    }
}

int main(){
    cin>>n>>q;
    int sup;
    for (int i = 2; i<=n; ++i){
        cin>>sup;
        adj[sup].pb(i);
    }
    cnt = 1;
    res.pb(0);
    dfs(1);
    int com, idx, last, sz, posFi,posLast;
    /*
    for (int i = 0; i<n; ++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    */
    while(q--){
        cin>>com>>idx;
        sz =  adj[com].size();
        last = adj[com][sz-1];
        posFi = pos[com];
        posLast = pos[last];
        if (idx>posLast-posFi+1) cout<<-1<<endl;
        else{

            cout<<res[posFi+idx-1]<<endl;
        }
    }
    return 0;
}
