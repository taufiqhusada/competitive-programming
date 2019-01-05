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

int n,m,x,y;
string s;
int hitam[1005],putih[1005];
int dp[1005][2];

int solve(int pos, int n, bool warna){
    if (n<=0) return 0;
    if (dp[pos][warna]!=-1) return dp[pos][warna];
    int &ret = dp[pos][warna];
    if (warna==0){
        int ans = INF;
        FOR(i,x,min(y,n)){
            int cnthit = 0;
            FORD(j,pos,pos-i+1) cnthit+=hitam[j];
            ans = min(ans,cnthit+solve(pos-i,n-i,1));
        }
        //cout<<ans<<" "<<n<<endl;
        return ret = ans;
    }
    else{
        int ans = INF;
        FOR(i,x,min(y,n)){
            int cntput = 0;
            FORD(j,pos,pos-i+1) cntput+=putih[j];
            ans = min(ans,cntput+solve(pos-i,n-i,0));
        }
        //cout<<ans<<" "<<n<<endl;
        return ret = ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y;
    REP(i,n){
        cin>>s;
        REP(j,m){
            if (s[j]=='#') hitam[j]++;
            else putih[j]++;
        }
    }
    RESET(dp,-1);
    cout<<min(solve(m-1,m,0),solve(m-1,m,1))<<endl;
}
