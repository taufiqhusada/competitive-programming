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

string s;
int z[1000005];
int cnt;

void zfunction(string s){
    int n = s.length();
    int l = 0, r = 0;
    FOR(i,1,n/2){
        if (i<=r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]-1>r){
            l = i;
            r = i+ z[i]-1;
        }
        if (z[i]>=i) cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    if (s[0]=='0'){
        cout<<0<<endl;
        return 0;
    }
    cnt = 0;
    zfunction(s);
    cout<<cnt<<endl;
}
