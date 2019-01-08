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
string s,t;
int a[30],pref,suff,cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s>>t;
    pref = -1;
    REP(i,n){
        if (s[i]==t[i]) pref = i;
        else break;
    }
    suff = n;
    FORD(i,n-1,0){
        if (s[i]==t[i]) suff = i;
        else break;
    }
    //cout<<pref<<" "<<suff<<endl;
    string ss = s.substr(pref+1,suff-pref-1);
    string tt = t.substr(pref+1,suff-pref-1);
    if (ss.length()==0){
        cout<<0<<endl;
        return 0;
    }
    //cout<<ss<<" "<<tt<<endl;
    if ((ss.substr(1)).compare(tt.substr(0,tt.length()-1))==0) cnt++;
    if ((tt.substr(1)).compare(ss.substr(0,ss.length()-1))==0) cnt++;
    cout<<cnt<<endl;

}
