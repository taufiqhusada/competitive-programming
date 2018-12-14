#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,cnt1,len;
ll a[200005];
ll g[200005];
ll gc;

int main(){
	cin>>n;
	for (int i = 0; i<n; ++i){
		cin>>a[i];
		if (a[i]==1) cnt1++;
	}
	if (cnt1>0){
		cout<<n-cnt1<<endl;
	}
	else{
		len = n+5;
		for (int i = 0; i<n-1; ++i){
			gc = a[i];
			for (int j = i+1; j<n; ++j){
				gc = __gcd(gc,a[j]);
				if (gc==1) len = min(len,j-i);
			}
		}

		if (len>n) cout<<-1<<endl;
		else cout<<len+n-1<<endl;
	}


}
