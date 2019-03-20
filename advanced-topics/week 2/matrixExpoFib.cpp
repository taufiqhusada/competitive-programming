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
typedef vector<vector<ll> > matrix;

matrix mul(matrix a, matrix b){
    matrix c;
    REP(i,2){
        std::vector<ll> g;
        REP(j,2){
            g.pb(0);
        }
        c.pb(g);
    }
    REP(i,2){
        REP(j,2){
            REP(k,2){
                c[i][j] += ((a[i][k]%MOD)*(b[k][j]%MOD))%MOD;
            }
        }
    }
    return c;
}

matrix mpow(matrix a, ll p){
    if(p==1) return a;
    if(p%2==1) return mul(a,mpow(a,p-1));
    matrix x = mpow(a,p/2);
    return mul(x,x);
}

ll fibo(int k, matrix T){
    int f0 = 0;
    int f1 = 1;
    if(k==0)return f0;
    if(k==1)return f1;
    matrix g = mpow(T,k);
    return (g[0][0]*f0+g[0][1]*f1)%MOD;
}

int tc;
ll x,y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    matrix t;
    std::vector<ll> t1,t2;
    t1.pb(0);t1.pb(1);t2.pb(1);t2.pb(1);
    t.pb(t1);t.pb(t2);
    cin>>tc;
    while(tc--){
        cin>>x>>y;
        cout<<(fibo(y+2,t)%MOD-fibo(x+1,t)%MOD)%MOD<<endl;
    }
}
