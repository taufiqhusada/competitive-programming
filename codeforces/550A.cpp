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
std::vector<int> a,b;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.length();
    REP(i,n-1){
        if (s[i]=='A' && s[i+1]=='B') a.pb(i);
        if (s[i]=='B' && s[i+1]=='A') b.pb(i);
    }
    if (a.empty() || b.empty()){
        cout<<"NO"<<endl;
        return 0;
    }
    /*REP(i,a.size()){
        cout<<a[i]<<" ";
    }cout<<endl;
    REP(i,b.size()){
        cout<<b[i]<<" ";
    }cout<<endl;*/
    if ((a[a.size()-1]>=b[0]+2)|| (b[b.size()-1]>=a[0]+2) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
