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

int n,m,a,b;
ll cnt[100005];
std::vector<vi> v(100005);
ll prefsum;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n){
        cin>>a>>b;
        v[a].pb(b);
    }
    FOR(i,1,m){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    /*
    FOR(i,1,m){
        REP(j,v[i].size()){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/
    FOR(i,1,m){
        int j = 0;
        int sz = v[i].size();
        prefsum = 0;
        while (j<sz){
            prefsum += v[i][j];
            if (prefsum<0) break;
            cnt[j]+=prefsum;
            j++;
        }
    }
    ll ans = 0;
    REP(i,n) {
        ans= max(ans,cnt[i]);
    }
    cout<<ans<<endl;
}
