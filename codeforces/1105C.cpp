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

ll l,r,dp[200005][3];
int n, cnt0,cnt1,cnt2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>r;
    l--;
    cnt0=r/3-l/3;
	cnt1=(r+2)/3-(l+2)/3;
	cnt2=(r+1)/3-(l+1)/3;
    dp[1][0] = cnt0;
    dp[1][1] = cnt1;
    dp[1][2] = cnt2;
    FOR(i,2,n){
        dp[i][0] = (dp[i-1][1]*cnt2 + dp[i-1][2]*cnt1 + dp[i-1][0]*cnt0)%MOD;
        dp[i][1] = (dp[i-1][2]*cnt2 + dp[i-1][0]*cnt1 + dp[i-1][1]*cnt0)%MOD;
        dp[i][2] = (dp[i-1][1]*cnt1 + dp[i-1][0]*cnt2 + dp[i-1][2]*cnt0)%MOD;
    }
    cout<<dp[n][0]<<endl;
}
