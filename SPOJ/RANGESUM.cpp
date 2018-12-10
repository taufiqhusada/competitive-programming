// SPOJ RANGESUM - Range Sum

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

int n,q,op,l,r,now;
ll x;

int main(){
	cin>>n;
	ll a[n+1];
	for (int i = 1; i<=n; i++){
		cin>>a[i];
	}
	vector <ll> v;
	v.pb(0);
	for (int i = n; i>=1; i--){
		v.pb(a[i]);
		v[n-i+1] += v[n-i];
	}
	cin>>q;
	now = n;
	while(q--){
		cin>>op;
		if (op==2){
			now++;
			cin>>x;
			v.pb(x);
			v[now] += v[now-1];
		}
		else{
			cin>>l>>r;
			cout<<v[now-l+1] - v[now-r]<<endl;
		}
	}
	return 0;
}
