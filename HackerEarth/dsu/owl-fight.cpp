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

int dsu[10005],ans,val[10005];

void init(int n){
    FOR(i,1,n){
        dsu[i] = i;
        val[i] = i;
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
    val[root_b] = max(val[root_a],val[root_b]);
}

bool find(int a, int b){
    return root(a)==root(b);
}

int n,m,q,x,a,b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    init(n);
    REP(i,m){
        cin>>a>>b;
        join(a,b);
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        int vala = val[root(a)];
        int valb = val[root(b)];
        //cout<<root(a)<<">>"<<vala<<" "<<root(b)<<">>"<<valb<<endl;
        if (find(a,b))cout<<"TIE"<<endl;
        else if (vala>valb) cout<<a<<endl;
        else if (valb>vala) cout<<b<<endl;
        else cout<<"TIE"<<endl;
    }
}
