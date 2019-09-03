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
int a[150005];
bool ada[150005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    REP(i,n){
        if (ada[a[i]+1]){
            if (ada[a[i]]) if (a[i]>1)ada[a[i]-1] = true;
            ada[a[i]] = true;
        }
        ada[a[i]+1] = true;
    }
    int sum = 0;
    REP(i,150005){
        if (ada[i])sum++;
    }
    cout<<sum<<endl;
}
