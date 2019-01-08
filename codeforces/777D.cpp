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
string s[500005];
int len[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n) {
        cin>>s[i];
        len[i] = s[i].length();
    }
    FORD(i,n-1,1){
        int minlen = min(len[i],len[i-1]);
        bool samaterus = true;
        REP(j,minlen){
            if (s[i][j]>s[i-1][j]) {
                samaterus = false;
                break;
            }
            if (s[i][j]<s[i-1][j]){
                len[i-1] = j;
                samaterus = false;
                break;
            }
        }
        if (samaterus){
            if (len[i]<len[i-1]) len[i-1] = minlen;
        }
    }
    REP(i,n){
        //cout<<len[i]<<endl;
        cout<<s[i].substr(0,len[i])<<endl;
    }
}
