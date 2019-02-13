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

int n;
ll goal,ans;
ll a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>goal;
    REP(i,n) cin>>a[i];
    ll l = 1, r = INF, mid;
    while(l<=r){
        mid = (l+r)/2;
        ll temp = 0;
        REP(i,n)temp += mid/a[i];
        if (temp>=goal){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
}
