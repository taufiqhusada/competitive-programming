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

const int N = 5 * 100 * 1000 + 5;
int n,m;
int par[N], sz[N];

void init(int n){
    FOR(i,1,n){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

void join(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x != y){
        if(sz[y] > sz[x])swap(x,y);
        sz[x] += sz[y];
        par[y] = x;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    init(n);
    REP(i,m){
        int k,fi;
        cin>>k;
        if (k>=1)cin>>fi;
        int a;
        REP(j,k-1){
            cin>>a;
            join(a,fi);
        }
    }
    FOR(i,1,n) {
        cout<<sz[find(i)]<<" ";
    }
}
