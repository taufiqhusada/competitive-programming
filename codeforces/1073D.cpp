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
ll jum;
ll t,a[200005],mini;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    mini = INF+5;
    REP(i,n){
        cin>>a[i];
        mini = min(mini,a[i]);
    }
    ll ans = 0;
    while(t>=mini){
        jum = 0;
        ll temp = t;
        REP(i,n){
            if (temp>=a[i]){
                temp-=a[i];
                jum++;
            }
        }
        ans+=(t/(t-temp))*jum;
        t = t%(t-temp);
        //cout<<ans<<endl;
        //cout<<t<<endl;
    }
    cout<<ans<<endl;

}
