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

int dsu[150000],sz[150000],done[150000];

void init(int n){
    FOR(i,1,n){
        dsu[i] = i;
        sz[i] = 1;
    }
}

int root(int u){
    while(dsu[u]!=u){
        u = dsu[u];
    }
    return u;
}

void join(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(size[root_A] < size[root_B ]){
        dsu[ root_A ] = dsu[root_B];
        sz[root_B] += sz[root_A];
    }
    else{
        dsu[ root_B ] = dsu[root_A];
        sz[root_A] += sz[root_B];
    }

bool find(int a, int b){
    return root(a)==root(b);
}

int n, a, b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    init(n);
    REP(i,n-1){
        cin>>a>>b;
        join(a,b);
                }

}
