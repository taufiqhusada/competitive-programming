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
ll dp[(1<<5)+5][10005][2];
int vowel[10005];

ll solve(int mask, int pos, int turn){
    if (pos>=n) return 0;
    if (turn==3){
        if (mask>0){
            //cout<<pos<<" "<<mask<<endl;
            return dp[mask][pos][turn] = 1;
        }
        else return 0;
    }
    else if (dp[mask][pos][turn] != -1) return dp[mask][pos][turn];
    ll &ret = dp[mask][pos][turn] = solve(mask,pos+1,turn);
    if ((mask&vowel[pos])>0) ret += solve(mask&vowel[pos],pos+1,turn+1);
    return ret;
}

string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        RESET(vowel,0);
        cin>>n;
        REP(i,n){
            cin>>s;
            REP(j,s.length()){
                if (s[j]=='a')vowel[i] |= 1;
                else if (s[j]=='i') vowel[i]|=2;
                else if (s[j]=='u') vowel[i]|=4;
                else if (s[j]=='e') vowel[i]|=8;
                else if (s[j]=='o') vowel[i]|=16;
            }
            //cout<<vowel[i]<<endl;
        }
        RESET(dp,-1);
        cout<<solve(31,0,0)<<endl;
    }
}
