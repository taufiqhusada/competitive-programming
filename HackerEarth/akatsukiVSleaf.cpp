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

int n,aintmask;
int akatx[25], akaty[25], leafx[25],leafy[25];
int dp[(1<<20) + 5][25];

int solve(int mask, int pos){
    if (mask==aintmask && pos==n) return 0;
    if (dp[mask][pos]>=0) return dp[mask][pos];
    int ans = INF;
    REP(i,n){
        if(!(mask&(1<<i))){
            ans = min(ans, abs(akatx[i]-leafx[pos]) + abs(akaty[i]-leafy[pos]) + solve(mask|(1<<i),pos+1));
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>akatx[i]>>akaty[i];
    }
    REP(i,n){
        cin>>leafx[i]>>leafy[i];
    }
    aintmask = (1<<n) - 1;
    RESET(dp,-1);
    cout<<solve(0,0);
}
