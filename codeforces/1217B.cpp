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
int n;
ll x, maxi, lost, tumbuh, a, b, now;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n>>now;
        cin>>a>>b;
        ll maxi = (a-b);
        ll maxblow = a;
        lost = a;
        tumbuh = b;
        FOR(i,1,n-1){
            cin>>a>>b;
            if (a-b>maxi){
                maxi = a-b;
                lost = a;
                tumbuh = b;
            }
            maxblow = max(a,maxblow);
        }
        if (maxi<=0){
            if (maxblow>=now) cout<<1<<endl;
            else cout<<-1<<endl;
        }
        else if (maxblow>=now){
            cout<<1<<endl;
        }
        else{
            now-=maxblow;
            if (now%maxi==0){
                cout<<now/maxi+1<<endl;
            }
            else{
                cout<<now/maxi+2<<endl;
            }
        }
    }
}
