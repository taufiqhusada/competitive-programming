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

int x,k,A,b;
std::vector<int> a;
ll n,num;

ll dnc(ll l,ll r){
    ll lo = lower_bound(a.begin(),a.end(),l)-a.begin();
    ll hi = upper_bound(a.begin(),a.end(),r)-a.begin();
    hi--;
    ll total = (hi-lo+1);
    ll power = A;
    if (total>0) power = b*total*(r-l+1);
    if (l==r || total==0){
        return power;
    }
    ll mid = (l+r)/2;
    ll kiri = dnc(l,mid);
    ll kanan = dnc(mid+1,r);
    return min(kiri+kanan,power);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>k>>A>>b;
    n = pow(2,x);
    FOR(i,1,k){
        cin>>num;
        a.pb(num);
    }
    sort(a.begin(),a.end());
    cout<<dnc(1,n)<<endl;
}
