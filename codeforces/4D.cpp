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
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;

int n,wid,hei;
std::vector<pair<pii, int> > wh;
int w,h;
int dp[5005],nxpos[5005];

int solve(int pos){
    int &ret = dp[pos];
    if (ret!=-1) return ret;
    ret = 1;
    FOR(i,pos+1,n-1){
        if (wh[i].fi.fi>wh[pos].fi.fi && wh[i].fi.se>wh[pos].fi.se){
            int newres = 1+solve(i);
            if (newres>ret){
                ret = newres;
                nxpos[wh[pos].se] = wh[i].se;
            }
        }
    }
    return ret;
}

int idx;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>wid>>hei;
    REP(i,n){
        cin>>w>>h;
        wh.pb(mp(mp(w,h),i));
    }
    sort(wh.begin(),wh.end());
    RESET(dp,-1);
    int ans = -1;
    REP(i,n){
        if (wh[i].fi.fi>wid && wh[i].fi.se>hei){
            int temp = solve(i);
            //cout<<temp<<endl;
            if (temp>ans){
                ans = temp;
                idx = wh[i].se;
            }
        }
    }
    if (ans!=-1)cout<<ans<<endl;
    else cout<<0<<endl;
    REP(i,ans){
        cout<<idx+1<<" ";
        idx = nxpos[idx];
    }
}
