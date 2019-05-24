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
string s;
bool cek[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    int cnt = 0;
    RESET(cek,1);
    REP(i,n-1){
        if (s[i]==s[i+1]){
            cnt++;
            cek[i]=0;
        }
        else{
            i++;
        }
    }
    int len = 0;
    REP(i,n){
        if (cek[i]) len++;
    }
    if (len&1) {
        cek[n-1] = 0;
        cnt++;
    }
    cout<<cnt<<endl;
    REP(i,n){
        if (cek[i]) cout<<s[i];
    }
}
