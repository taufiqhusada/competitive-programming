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

int z[85], cnt[1000005], maxi;

void zfunction(string s){
    int n = s.length();
    int l = 0, r = 0;
    FOR(i,1,n-1){
        if (i<=r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]-1>r){
            l = i;
            r = i+ z[i]-1;
        }
        cnt[z[i]]++;
    }
}

string s;
int t;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        RESET(z,0);
        RESET(cnt,0);
        cin>>s;
        zfunction(s);
        int n = s.length();
        z[0] = n;
        cnt[n] = 1;
        FORD(i,n-1,1){
            cnt[i]+=cnt[i+1];
        }
        int ans = INF;
        REP(i,n){
            if (z[i]*cnt[z[i]]==n) ans = min(ans,z[i]);
        }
        cout<<ans<<endl;
    }

}
