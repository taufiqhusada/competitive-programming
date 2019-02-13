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

int n,a[100005],temp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int cnt = 0;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n){
        while(a[i]!=i){
            cnt++;
            temp = a[a[i]];
            a[a[i]] = a[i];
            a[i] = temp;
        }
    }
    cout<<cnt<<endl;
}
