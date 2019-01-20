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
ll l[300005],r[300005],prefl[300005],prefr[300005],suffl[300005],suffr[300005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>l[0]>>r[0];
    prefl[0] = l[0];
    prefr[0] = r[0];
    FOR(i,1,n-1){
        cin>>l[i]>>r[i];
        prefl[i] = max(prefl[i-1],l[i]);
        prefr[i] = min(prefr[i-1],r[i]);
    }
    suffl[n-1] = l[n-1];
    suffr[n-1] = r[n-1];
    FORD(i,n-2,0){
        suffl[i] = max(suffl[i+1],l[i]);
        suffr[i] = min(suffr[i+1],r[i]);
    }
    ll ans = 0;
    FOR(i,1,n-2){
        ans = max(ans,min(prefr[i-1],suffr[i+1]) -max(prefl[i-1],suffl[i+1]) );
    }
    ans = max(ans,suffr[1]-suffl[1]);
    ans = max(ans,prefr[n-2]-prefl[n-2]);
    cout<<ans<<endl;
}
