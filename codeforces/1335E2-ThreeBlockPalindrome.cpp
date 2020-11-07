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

int t,n;
int maxnum;
int a[200005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        std::vector<vi> v(205);
        int cnt[205][n+5];
        RESET(cnt, 0);
        maxnum  = -1;
        for (int i = 0; i<n; ++i){
            cin>>a[i];
            v[a[i]].pb(i);
            cnt[a[i]][i]++;
            maxnum = max(maxnum, a[i]);
        }
        for (int i = 1; i<=maxnum; ++i){
            for (int j = 1; j<n; ++j){
                cnt[i][j] += cnt[i][j-1];
            }
        }

        int ans = 0;

        
        for (int i = 1; i<=maxnum; ++i){
            ans = max(ans,(int)v[i].size() );
            for (int j = 0; j<v[i].size()/2; ++j){
                int l = v[i][j];
                int r = v[i][(int)v[i].size() - j - 1];
                for (int k = 1; k<=maxnum; ++k){
                    if (k==i) continue;
                    if (l==0) ans = max(ans, (j+1)*2 + cnt[k][r]);
                    else ans = max(ans, (j+1)*2 + cnt[k][r] - cnt[k][l-1]);
                    // if (i==3) cout<<(j+1)*2<<" "<<l<<" "<<r<<" "<<k<<" "<<ans<<" "<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
}
