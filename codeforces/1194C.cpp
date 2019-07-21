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

int q;
string s,t,p;
int cnts[30],cntp[30],cntt[30];

bool isSubSequence(string str1, string str2, int m, int n)
{
    // Base Cases
    if (m == 0) return true;
    if (n == 0) return false;

    // If last characters of two strings are matching
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    // If last characters are not matching
    return isSubSequence(str1, str2, m, n-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
        cin>>s>>t>>p;
        RESET(cnts,0);
        RESET(cntp,0);
        RESET(cntt,0);
        REP(i,s.length())cnts[s[i]-'a']++;
        REP(i,p.length())cntp[p[i]-'a']++;
        REP(i,t.length())cntt[t[i]-'a']++;
        bool ok = isSubSequence(s,t,s.length(),t.length());
        REP(i,26){
            if (cnts[i]+cntp[i]<cntt[i]){
                ok = false;
                break;
            }
        }
        if (ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
