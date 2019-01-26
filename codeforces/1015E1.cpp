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

std::vector<pair<pair<int,int>,int > > v;
char a[105][105];
char b[105][105];
int n,m;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1};
int sz,dis;
bool ok;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    REP(i,n){
        cin>>s;
        REP(j,m){
            a[i][j]=s[j];
            b[i][j] = '.';
        }
    }
    REP(i,n){
        REP(j,m){
            sz = 0;
            ok = true;
            dis = 1;
            if (a[i][j]=='*'){
                while(ok){
                    REP(k,4){
                        if (i+x[k]*dis>=0 && i+x[k]*dis<n && j+y[k]*dis>=0 && j+y[k]*dis<m){
                            if (a[i+x[k]*dis][j+y[k]*dis]=='.'){
                                ok = false;
                                break;
                            }
                        }
                        else{
                            ok = false;
                            break;
                        }
                    }
                    if (ok){
                        sz++;
                        b[i][j] = '*';
                        REP(k,4){
                            b[i+x[k]*dis][j+y[k]*dis]='*';
                        }
                        dis++;
                    }
                    else{
                        if (sz>=1){
                            v.pb(mp(mp(i+1,j+1),sz));
                        }
                    }
                }
            }
        }
    }
    /*
    REP(i,n){
        REP(j,m){
            cout<<b[i][j];
        }
        cout<<endl;
    }
    */
    REP(i,n){
        REP(j,m){
            if (a[i][j]!=b[i][j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<v.size()<<endl;
    REP(i,v.size()){
        cout<<v[i].fi.fi<<" "<<v[i].fi.se<<" "<<v[i].se<<endl;
    }
}
