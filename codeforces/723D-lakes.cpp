#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back

int n,m,k,cnt,ans,realcnt;
string s;
char a[55][55];
bool visited[55][55],valid;
vector<pair<int, pair<int,int> > >v;

int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};

void dfs(int i, int j){
    visited[i][j]= true;
    if (i==0 || j==0 || i==n-1 || j==m-1){
        v[cnt].fi = 99999;
        valid = false;
    }
    v[cnt].fi++;
    for (int k = 0; k<4; ++k){
        if (i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m && visited[i+x[k]][j+y[k]]==false && a[i+x[k]][j+y[k]]=='.'){
            dfs(i+x[k],j+y[k]);
        }
    }
}

void fill (int i, int j){
    a[i][j] = '*';
    for (int k = 0; k<4; ++k){
        if (i+x[k]>=0 && i+x[k]<n && j+y[k]>=0 && j+y[k]<m && a[i+x[k]][j+y[k]]=='.'){
            fill(i+x[k],j+y[k]);
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for (int i = 0; i<n; ++i){
        cin>>s;
        for (int j = 0; j<m; ++j){
            a[i][j] = s[j];
        }
    }
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            if (visited[i][j]==false && a[i][j]=='.'){
                v.pb(mp(0,mp(i,j)));
                valid = true;
                dfs(i,j);
                cnt++;
                if (valid)realcnt++;
            }
        }
    }
    //cout<<cnt<<endl;
    //cout<<realcnt<<endl;
    sort(v.begin(),v.end());

    for (int i = 0; i<v.size(); ++i){
        if (realcnt==k) break;
        if (v[i].fi!=0){
            ans += v[i].fi;
            int koorx = v[i].se.fi, koory = v[i].se.se;
            fill(koorx,koory);
            realcnt--;
        }
    }
    cout<<ans<<endl;
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
