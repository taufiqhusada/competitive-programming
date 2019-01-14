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
int dsu[50005],ans;

void init(int n){
    REP(i,n){
        dsu[i] = i;
    }
}

int root(int u){
    while(dsu[u]!=u){
        u = dsu[u];
    }
    return u;
}

void join(int a, int b){
    dsu[root(a)] = root(b);
}

bool find(int a, int b){
    return root(a)==root(b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool cek = true;
    int tc = 1;
    while(cek){
        cin>>n>>m;
        if (n==0 && m==0){
            cek = false;
        }
        else{
            RESET(dsu,0);
            ans = n;
            init(n);
            REP(i,m){
                cin>>a>>b;
                if (!find(a,b)){
                    join(a,b);
                    ans--;
                }
            }
            cout<<"Case "<<tc<<": "<<ans<<endl;
            tc++;
        }
    }
}
