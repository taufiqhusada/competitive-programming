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

int dsu[100005],ans;

void init(int n){
    FOR(i,1,n){
        dsu[i] = i;
    }
}

int root(int u){
    while(dsu[u]!=u){
        u = dsu[u];
    }
    return u;
}

void join(int a, int b){
    dsu[root(a)] = root(b);
}

bool find(int a, int b){
    return root(a)==root(b);
}

void changelead(int a){
    int root_a = root(a);
    if (root_a!=a){
        dsu[root_a] =  a;
        dsu[a] = a;
    }
}

int n,q;
int op,a,b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    init(n);
    while(q--){
        cin>>op;
        if (op==1){
            cin>>a>>b;
            if (!find(a,b)) join(a,b);
        }
        else if (op==2){
            cin>>a;
            changelead(a);
        }
        else{
            cin>>a;
            cout<<root(a)<<endl;
        }
    }
}
