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

int n, open[500006], close[500006], cnt;
string b;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>b;
        bool ok  = true;
        cnt = 0;
        int len = b.length();
        REP(j,len){
            if (b[j]=='(') cnt++;
            else cnt--;
        }
        if (cnt>=0){
            int cur = 0;
            REP(j,len){
                if (b[j]=='(') cur++;
                else cur--;
                if (cur<0){
                    ok = false;
                    break;
                }
            }
        }
        else{
            int cur = 0;
            for(int j = len-1; j>=0; --j){
                if (b[j]==')') cur++;
                else cur--;
                if (cur<0){
                    ok = false;
                    break;
                }
            }
        }
        if (ok){
            if (cnt>=0){
                open[cnt]++;
            }
            else{
                close[-cnt]++;
            }
        }

    }
    int ans = open[0]/2;
    FOR(i,1,500005){
        ans+= min(open[i],close[i]);

    }
    cout<<ans<<endl;
}
