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

std::vector<vii> v(100005);
vii ans;
int cnt;
vii a;
int x,n,m,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n){
        cin>>x;
        a.pb(mp(x,i+1));
    }
    sort(a.begin(),a.end());
    if (n==1){
        if (a[0].se==0)cout<<0<<endl;
        else cout<<-1<<endl;
    }
    else if (a[0].fi==1){
        cout<<-1<<endl;
    }
    else{
        if (a[1].fi==0){
            cout<<-1<<endl;
            return 0;
        }
        else{
            v[0].pb(mp(a[0].se,k));
            FOR(i,1,n-1){
                int vnow = a[i].se;
                int dis = a[i].fi;
                if (v[dis-1].size()==0){
                    cout<<-1<<endl;
                    return 0;
                }
                else{
                    v[dis-1][0].se--;
                    ans.pb(mp(v[dis-1][0].fi,vnow));
                    cnt++;
                    if (v[dis-1][0].se==0) v[dis-1].erase(v[dis-1].begin());
                    if (k>1) v[dis].pb(mp(vnow,k-1));
                }
            }
        }
        cout<<cnt<<endl;
        REP(i,ans.size()){
            cout<<ans[i].fi<<" "<<ans[i].se<<endl;
        }
    }
}
