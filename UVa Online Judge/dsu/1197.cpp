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

int dsu[30005],ans,sz[30005];

void init(int n){
    REP(i,n){
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
    int root_a = root(a);
    int root_b = root(b);
    dsu[root_a] = root_b;
    sz[root_b] += sz[root_a];
}

bool find(int a, int b){
    return root(a)==root(b);
}

int n,m,jum,awal,x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool cek = true;
    while (cek){
        cin>>n>>m;
        if (n==0 && m==0) return 0;
        else{
            RESET(dsu,0);
            RESET(sz,0);
            init(n);
            REP(i,m){
                cin>>jum;
                if (jum==0) continue;
                cin>>awal;
                if (jum==1) continue;
                REP(j,jum-1){
                    cin>>x;
                    if (!find(x,awal)) join(x,awal);
                }
                //cout<<"hasil "<<sz[awal]<<endl;
            }
        }
        int parent = root(0);
        cout<<sz[parent]<<endl;
    }

}
