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


ll dp[10000005];
ll cnt[10000005];
bool prime[10000005];

void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p; i<=n; i += p){
                prime[i] = false;
                dp[p]+=cnt[i];
            }
        }
    }
}

ll n,x,l,r;
int q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>x;
        cnt[x]++;
    }
    SieveOfEratosthenes(10000000);
    FOR(i,3,10000000) dp[i]+=dp[i-1];
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<dp[min(r,1LL*10000000)]-dp[min(l,1LL*10000000)-1]<<endl;
    }
}
