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

int pref[200005][30],n,jum[30],m;
string s,x;

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    REP(i,n){
        pref[i][s[i]-'a']++;
    }
    FOR(i,1,n){
        REP(j,26){
            pref[i][j]+=pref[i-1][j];
        }
    }
    cin>>m;
    REP(q,m){
        cin>>x;
        REP(i,26)jum[i]=0;
        REP(i,x.length()){
            jum[x[i]-'a']++;
        }
        int lo = 0, hi = n-1,mid,ans;
        while(lo<=hi){
            bool ok = true;
            //cout<<mid<<endl;
            mid = (lo+hi)/2;
            //cout<<lo<<" "<<hi<<endl;
            REP(i,26){
                if (jum[i]>pref[mid][i]){
                    ok = false;
                    //cout<<i<<":"<<pref[mid][i]<<endl;
                    break;
                }
            }
            if (ok){
                hi = mid-1;
                ans = mid;
                //cout<<ans<<endl;
            }
            else lo = mid+1;
        }
        cout<<ans+1<<endl;
    }
}
