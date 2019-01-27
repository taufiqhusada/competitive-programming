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

int n,lastpos,cur,maxi,cnt,cntg;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    int i = 0;
    while(i<n){
        //cout<<i<<endl;
        if (s[i]=='G'){
            cur++;
            i++;
        }
        if (s[i]=='S'){
            if (cnt==0){
                cur++;
                cnt++;
                lastpos = i;
                i++;
            }
            else{
                i = lastpos+1;
                maxi = max(cur,maxi);
                cur = 0;
                cnt = 0;
            }
        }
        maxi = max(cur,maxi);
    }
    REP(i,n){
        if (s[i]=='G') cntg++;
    }
    if (cntg>0) cout<<min(maxi,cntg)<<endl;
    else cout<<0<<endl;
}
