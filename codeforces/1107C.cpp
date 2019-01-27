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

int n,k;
ll a[200005];
std::vector<ll> v;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n) cin>>a[i];
    cin>>s;
    char prec = s[0];
    ll ans = 0;
    v.pb(a[0]);
    FOR(i,1,n-1){
        if (s[i]==prec) v.pb(a[i]);
        else{
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            REP(i,min(k,(int)v.size())){
                ans+=v[i];
                //cout<<v[i]<<endl;
            }
            v.clear();
            v.pb(a[i]);
        }
        prec = s[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    REP(i,min(k,(int)v.size())){
        ans+=v[i];
        //cout<<v[i]<<endl;
    }
    cout<<ans<<endl;
}
