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

int n,k;
ll p,a[10005],b[20005];

ll solve(int pos){
    ll res =0;
    int j = 0;
    res = -1;
    FOR(i,pos,pos+n-1){
        res = max(res,abs(a[j]-b[i]) + abs(b[i]-p));
        j++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>p;
    REP(i,n) cin>>a[i];
    REP(i,k) cin>>b[i];
    sort(a,a+n);
    sort(b,b+k);
    if (n==k){
        cout<<solve(0)<<endl;
    }
    else{
        ll temp = 999999999999999;
        REP(i,k-n+1){
            //cout<<solve(i)<<endl;
            temp = min(temp,solve(i));
        }
        cout<<temp<<endl;
    }
}
