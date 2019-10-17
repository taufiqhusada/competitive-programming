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

bool ada;
ll numW,numL;

void solution(ll a, ll b, ll n, ll nn)
{
    // traverse for all possible values
    if (n%__gcd(a,b) != 0) return;
    for (ll i = max(n/a,1LL*0); (i * a <= n+abs(b*nn)); i++) {
        // check if it is satisfying the equation
        if (((n - (i * a)) % b == 0) && (((n - (i * a))/b)>=0)) {
            numW = i;
            numL = (n - (i * a)) / b;
            // cout<<numW<<numL<<endl;
            //cout<<numW<<" "<<numL<<endl;
            if ((nn-numL-numW)>=0){
                ada = true;
                return;
            }

        }
    }
}

ll n,p,w,d;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>p>>w>>d;
    ll a = w-d;
    ll b = -d;
    ll c = p - n*d;
    // cout<<a<<b<<c<<endl;

    // cout<<(c%__gcd(a,b))<<endl;
    // cout<<((-c)%__gcd(-a,-b))<<endl;
    if (c>0)solution(a,b,c,n);
    else{
        solution(-a,-b,-c,n);
    }
    if (ada ){
        cout<<numW<<" "<<n-numL-numW<<" "<<numL<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
