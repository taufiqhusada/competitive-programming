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

int t,n;
ll a[305];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        REP(i,n) cin>>a[i];
        sort(a,a+n);
        ll ans = a[0]*a[n-1];
        std::vector<ll> b;
        for (ll i=2; i*i<=ans;++i){
            if (ans%i==0){
                b.pb(i);
                if (i*i!=ans) b.pb(ans/i);
            }
        }
        sort(b.begin(),b.end());
        if (b.size()!=n){
            cout<<-1<<endl;
        }
        else{
            bool cek = true;
            REP(i,n){
                if (b[i]!=a[i]){
                    cout<<-1<<endl;
                    cek = false;
                    break;
                }
            }
            if (cek) cout<<ans<<endl;
        }
    }
}
