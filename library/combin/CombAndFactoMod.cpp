#include<bits/stdc++.h>
using namespace std;

#define ll long long

const long long mod=998244353;
const int maxn=300005;


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
    int n, r;
    cin>>n>>r;
    cout<<comb(n,r)<<endl;
}
