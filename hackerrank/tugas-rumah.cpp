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

std::vector<ll> fibo;
ll a,b;

void generate(ll a,ll b){
    if (a+b<INF){
        fibo.pb(a+b);
        generate(b,a+b);
    }
}

ll x;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fibo.pb(1);
    fibo.pb(2);
    generate(1,2);
    // REP(i,fibo.size()){
    //     cout<<fibo[i]<<endl;
    // }
    bool bit[fibo.size()+1];
    RESET(bit,0);
    cin>>n;
    while(n--){
        cin>>x;
        RESET(bit,0);
        if (x==0) cout<<0<<endl;
        else{
            int pos = upper_bound(fibo.begin(),fibo.end(),x) - fibo.begin();
            //cout<<pos<<endl;
            pos--;
            x-=fibo[pos];
            int start = pos;
            bit[pos] =1;
            while(x>0){
                pos = upper_bound(fibo.begin(),fibo.end(),x) - fibo.begin();
                pos--;
                x-=fibo[pos];
                bit[pos] =1;
            }
            FORD(i,start,0){
                cout<<bit[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
