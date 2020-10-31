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

const long long mod=998244353;
const int maxn=300005;

int n,k;
std::vector<pair<int, int>> v;
int l,r;
ll facto[300005];

long long modpow(long long x, int y){
	long long ret=1;
	while (y>0){
		if (y&1){
			ret*=x;
			ret%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return ret;
}

long long modinv(long long x){
	return modpow(x,mod-2);
}

long long comb(long long a, long long b){
	if (a<b) return 0;
	return (((facto[a]*modinv(facto[b]))%mod)*modinv(facto[a-b]))%mod;
}

void init(){
	facto[0]=1;
	for (int i=1;i<maxn;i++) facto[i]=(facto[i-1]*i)%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    cin>>n>>k;
    for (int i =0; i<n; ++i){
        cin>>l>>r;
        v.pb({l,r});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int> > pq;

    ll prev = 0;
    ll ans = 0;
    for (int i = 0; i<n; ++i){
        if(pq.size()==0){
            pq.push(v[i].se);
            if (k==1){
                ans++;
            }
            continue;
        }

        while (!pq.empty() && pq.top() < v[i].fi){
            pq.pop();
        }
        pq.push(v[i].se);

        if (pq.size()==k){
            ans += 1;
        }
        else if (pq.size()>=k){
            int sz = pq.size();
            ans+=comb(sz,k)-comb(sz-1,k);
            ans%=mod;
            ans+=mod;
            ans%=mod;
        }


        // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans%mod<<endl;

}
