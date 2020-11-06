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

int a,b,c,d,x,y,z;
ll cnt[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d;
    for (int i = a; i<=b; ++i){
        cnt[i+b]++;
        cnt[i+c+1]--;
    }
    for (int i = 1; i<=1000001; ++i){
        cnt[i]+=cnt[i-1];
    }
    for (int i = 1; i<=1000001; ++i){
        cnt[i]+=cnt[i-1];
    }

    ll ans = 0;
    for (int i = c; i<=d; ++i){
        ans += cnt[1000001] - cnt[i];
    }
    cout<<ans<<endl;
}
