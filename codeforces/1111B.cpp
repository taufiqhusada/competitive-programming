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

ll n,k;
ll m,a[100005],cnt,presum[100005];
double ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    if (n==1){
        cin>>a[0];
        cout<<a[0]+min((ll)k,m)<<endl;
        return 0;
    }
    REP(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    presum[0] = a[0];
    FOR(i,1,n-1){
        presum[i]+= presum[i-1] + a[i];
    }
    ans = 0.0;
    REP(i,min(m+1,n)){
        ans = max(ans,(presum[n-i-1]*1.0 + min(m-i,k*(n-i)))/(n-i));
    }
    cout<<setprecision(12)<<ans<<endl;

}
