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
ll a[100005],dp[100005][2];
string s[100005],ss[100005],x;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n){
        cin>>x;
        s[i] = x;
        reverse(x.begin(),x.end());
        ss[i] = x;
    }
    REP(i,100005){
        REP(j,2){
            dp[i][j] = 999999999999999;
        }
    }
    dp[0][0] = 0;
    dp[0][1] = a[0];
    FOR(i,1,n-1){
        if (s[i]>=s[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if (s[i]>=ss[i-1]) dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if (ss[i]>=s[i-1]) dp[i][1] = min(a[i]+dp[i-1][0],dp[i][1]);
        if (ss[i]>=ss[i-1]) dp[i][1] = min(a[i]+dp[i-1][1],dp[i][1]);
    }
    if (dp[n-1][1]==999999999999999 && dp[n-1][0]==999999999999999)cout<<-1<<endl;
    else cout<<min(dp[n-1][1],dp[n-1][0])<<endl;
}
