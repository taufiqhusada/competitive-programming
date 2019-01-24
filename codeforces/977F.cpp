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
ll a[200005];
int dp[200005],prec[200005];
map<int,int> lastpos;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    lastpos.clear();
    int ans = -1;
    int posans  = 1;
    FOR(i,1,n){
        cin>>a[i];
        dp[i] = dp[lastpos[a[i]-1]] + 1;
        prec[i] = lastpos[a[i]-1];
        lastpos[a[i]] = i;
        if (dp[i]>ans){
            ans = dp[i];
            posans = i;
        }
    }
    std::vector<int> v;
    REP(i,ans){
        v.pb(posans);
        posans = prec[posans];
    }
    reverse(v.begin(),v.end());
    cout<<ans<<endl;
    FOR(i,0,v.size()-1){
        cout<<v[i]<<" ";
    }
}
