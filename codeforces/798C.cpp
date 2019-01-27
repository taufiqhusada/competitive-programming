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
ll a[100005];
int par[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>a[0];
    ll g = a[0];
    par[0] = a[0]%2;
    FOR(i,1,n-1) {
        cin>>a[i];
        g = __gcd(g,a[i]);
        par[i] = a[i]%2;
    }
    if (g>1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    int ans = 0;
    FOR(i,0,n-2){
        if (par[i]==1){
            if (par[i+1]==0){
                ans+=2;
            }
            else{
                ans++;
                par[i+1]=0;
            }
        }
    }
    if (par[n-1]==1) ans+=2;
    cout<<"YES"<<endl;
    cout<<ans<<endl;

}
