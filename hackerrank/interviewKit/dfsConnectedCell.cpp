#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int x[] = {1,0,-1,0,1,1,-1,-1};
int y[] = {0,1,0,-1,1,-1,1,-1};
int n,m,a[15][15];
int cnt;

void floodfill(int nowx, int nowy){
    a[nowx][nowy] = 0;
    cnt++;
    REP(k,8){
        if (nowx+x[k]>=0 && nowx+x[k]<n && nowy+y[k]>=0 && nowy+y[k]<m){
            if (a[nowx+x[k]][nowy+y[k]]==1)floodfill(nowx+x[k],nowy+y[k]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n){
        REP(j,m) cin>>a[i][j];
    }
    int maxi = -1;
    REP(i,n){
        REP(j,m){
            if (a[i][j]==1){
                cnt = 0;
                floodfill(i,j);
                maxi = max(maxi,cnt);
            }
        }
    }
    cout<<maxi<<endl;
}
