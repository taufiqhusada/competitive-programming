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

int t,a,b,c,d,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        if (a%c==0){
            a = a/c;
        }
        else{
            a = a/c+1;
        }
        if (b%d==0){
            b = b/d;
        }
        else{
            b = b/d+1;
        }
        if (a+b<=k){
            cout<<a<<" "<<b<<endl;
        }
        else cout<<-1<<endl;
    }
}
