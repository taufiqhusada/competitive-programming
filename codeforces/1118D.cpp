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

int n,cnt;
ll ans,m,kurang,a[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ll sum = 0;
    REP(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    int lo = 1, hi = n, mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        cnt = 0;
        kurang = 0;
        ll temp = 0;
        REP(i,n){
            temp+=max(a[i]-kurang,0LL);
            cnt++;
            if (cnt==mid){
                kurang++;
                cnt = 0;
            }
        }
        if (temp>=m){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    if (ans==0) cout<<-1<<endl;
    else cout<<ans<<endl;
}
