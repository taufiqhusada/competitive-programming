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
ll moves,k;
int a[200005];

bool cek(int median){
    moves = 0;
    FOR(i,n/2,n-1){
        if (median-a[i]>0) moves+=median-a[i];
        if (moves>k) return false;
    }
    if (moves<=k) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n) cin>>a[i];
    sort(a,a+n);
    ll l = 0,r = 2*INF,mid,ans;
    while(l<=r){
        mid = (l+r)/2;
        if (cek(mid)){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<endl;
}
