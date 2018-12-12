//  Codeforces Round #222 (Div. 1) - A. Maze

#include<bits/stdc++.h>
using namespace std;
#define t '.'

char a[505][505];
bool visit[505][505];
vector<pair<int,int> > v;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};

bool isValid(int i, int j, int n, int m){
    if (i>=0 && i<n && j<m && j>=0) return true;
    return false;
}

void dfs(int i, int j, int n, int m){
    visit[i][j] = 1;
    for (int k = 0; k<4; ++k){
        if (isValid(i+x[k],j+y[k],n,m)&&visit[i+x[k]][j+y[k]]==0){
            if (a[i+x[k]][j+y[k]]==t) dfs(i+x[k],j+y[k],n,m);
        }
    }
    v.push_back(make_pair(i,j));
}

int n,m,k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    string s;
    for (int i = 0; i<n; ++i){
        cin>>s;
        for (int j = 0; j<m; ++j){
            a[i][j] = s[j];
        }
    }
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            if (a[i][j]==t && visit[i][j]==0){
                dfs(i,j,n,m);
            }
        }
    }
    for (int i = 0; i<k; ++i){
        a[v[i].first][v[i].second] = 'X';
    }
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
