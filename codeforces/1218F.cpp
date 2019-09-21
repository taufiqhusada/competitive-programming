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

priority_queue<int, vector<int>, greater<int> > pq;
int a[100005], n, awal, gain, x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>awal;
    ll ans = 0;
    REP(i,n){
        cin>>a[i];
    }
    cin>>gain;
    REP(i,n){
        cin>>x;
        pq.push(x);
        while(awal<a[i] && !pq.empty()){
            int now = pq.top();
            ans+=now;
            awal+=gain;
            pq.pop();
        }
        if (awal<a[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
