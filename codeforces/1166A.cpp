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
string a[105];
int c[30];
int cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) cin>>a[i];
    REP(i,n){
        c[a[i][0]-'a']++;
    }
    int res = 0;
    REP(i,26){
        int x=c[i]/2;
        int y= (c[i]+1)/2;
        res+= x*(x-1)/2 + y*(y-1)/2;
    }
    cout<<res<<endl;
}
