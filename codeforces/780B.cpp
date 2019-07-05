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

const double eps = 1e-9;

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll x[60005],v[60005];
double lo,hi,m,l,r;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n)cin>>x[i];
    REP(i,n) cin>>v[i];
    lo = 0;
    hi = INF;
    double ans;
    while(hi-lo>=eps){
        m = (lo+hi)/2.0;
        l = 0;
        r = INF;
        FOR(i,0,n-1){
            l = max(l,x[i]-v[i]*m);
            r = min(r,x[i]+v[i]*m);
        }
        if (r-l>=eps){
            hi =m;
        }
        else{
            lo = m;
        }
    }
    cout<<setprecision(20)<<hi<<endl;
}
