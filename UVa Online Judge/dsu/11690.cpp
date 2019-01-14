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

int dsu[10005],ans,money[10005];

void init(int n){
    REP(i,n){
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
    int root_a = root(a);
    int root_b = root(b);
    dsu[root_a] = root_b;
    money[root_b] += money[root_a];
    //money[root_a] += money[root_b];
}

bool find(int a, int b){
    return root(a)==root(b);
}

int a,b,n,m,t;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>m;
        init(n);
        REP(i,n){
            cin>>money[i];
        }
        REP(i,m){
            cin>>a>>b;
            if (!find(a,b)) join(a,b);
        }
        bool cek = true;
        REP(i,n){
            if (money[root(i)]!=0){
                cout<<"IMPOSSIBLE";
                cek = false;
                break;
            }
        }
        if (cek) cout<<"POSSIBLE";
        if (t)cout<<endl;
    }

}
