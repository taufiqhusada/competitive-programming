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

int n,m,maxw,w[1005];
ll b[1005];

int dsu[1005],sz[1005];
std::vector<vi> v(1005);

void init(int n){
    FOR(i,1,n){
        dsu[i] = i;
        sz[i] = 1;
        v[i].pb(i);
    }
}

int root(int u){
    while(dsu[u]!=u){
        u = dsu[u];
    }
    return u;
}

void join(int a, int b){
    int root_A = root(a);
    int root_B = root(b);
    if(sz[root_A] < sz[root_B ]){
        dsu[root_A] = dsu[root_B];
        sz[root_B] += sz[root_A];
        for (auto i: v[root_A]) v[root_B].pb(i);
        v[root_A].clear();
    }
    else{
        dsu[root_B] = dsu[root_A];
        sz[root_A] += sz[root_B];
        for (auto i: v[root_B]) v[root_A].pb(i);
        v[root_B].clear();
    }
}

bool find(int a, int b){
    return root(a)==root(b);
}

ll dp[1005];
std::vector<int> grand;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>maxw;
    FOR(i,1,n) cin>>w[i];
    FOR(i,1,n) cin>>b[i];
    int x,y;
    init(n);
    REP(i,m){
        cin>>x>>y;
        join(x,y);
    }
    RESET(dp,0);
    FOR(i,1,n){
        if (root(i)==i){
            grand.pb(i);
        }
    }
    FOR(i,0,grand.size()){
        int grandv = grand[i];
        FORD(wnow,maxw,0){
            ll sumw = 0, sumb = 0;
            for(auto child: v[grandv]) {
                sumw+=w[child];
                sumb+=b[child];
                if (wnow>=w[child]) dp[wnow] = max(dp[wnow],dp[wnow-w[child]]+b[child]);
            }
            if (wnow>=sumw) dp[wnow] = max(dp[wnow],dp[wnow-sumw]+sumb);
            cout<<dp[wnow]<<endl;
        }
    }
    cout<<dp[maxw]<<endl;
}
