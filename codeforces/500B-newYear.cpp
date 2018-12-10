// Good Bye 2014 : B. New Year Permutation

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

std::vector<vector<int> > c(305);
std::vector<vector<int> > pos(305);

int mat[305][305],a[305], urutan[305],cc;
bool visit[305];

void dfs(int v, int n, int index){
  c[index].pb(a[v]);
  pos[index].pb(urutan[a[v]]);
  visit[v] = 1;
  for (int j = 1; j<=n; ++j){
    if (mat[v][j]==1 && visit[j]==0){
      dfs(j,n,index);
    }
  }
}

int n;

int main(){
  cin>>n;
  string in;
  for (int i = 1; i<=n; ++i) {
    cin>>a[i];
    urutan[a[i]] = i;
  }
  for (int i = 1; i<=n; ++i){
    cin>>in;
    for (int j = 1; j<=n; ++j){
      mat[i][j]=(int)in[j-1]-48;
    }
  }
  memset(visit,0,sizeof(visit));
  for (int i = 1; i<=n; ++i){
    if (visit[i]==0) {
      dfs(i,n,cc);
      cc++;
    }
  }
  for (int i = 0; i<cc; ++i){
    sort(c[i].begin(),c[i].end());
    sort(pos[i].begin(),pos[i].end());
  }
  for (int i = 0; i<cc; ++i){
    for (int j = 0; j<pos[i].size(); ++j){
      a[pos[i][j]] = c[i][j];
    }
  }
  /*
  for (int i = 0; i<cc; ++i){
    for (int j = 0; j<pos[i].size(); ++j){
      cout<<c[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  for (int i = 1;i<=n;++i){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;


}
