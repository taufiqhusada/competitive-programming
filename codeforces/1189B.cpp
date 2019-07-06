#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back
#define pf push_front
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
std::vector<ll> v;
ll x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>x;
        v.pb(x);
    }
    bool ok = true;
    sort(v.begin(),v.end());
    deque<ll> dq;
	REP(i,n){
		if (i & 1) dq.pb(v.back());
		else dq.pf(v.back());
		v.pop_back();
	}
    REP(i,n){
        ok = ok && dq[i] < (dq[(i-1+n)%n] + dq[(i+1)%n]);
    }
    if (ok){
        cout<<"YES"<<endl;
        REP(i,n){
            cout<<dq[i]<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }
}
