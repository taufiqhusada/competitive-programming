// Codeforces Round #260 (Div. 1) prob A: Boredom

#include<bits/stdc++.h>
using namespace std;

long long dp(long long a[], bool cek[],int pos, long long memo[]){
	if (pos<=0) return 0;
	if (cek[pos]==0) {memo[pos] = dp(a,cek,pos-1,memo); return memo[pos];}
	if (memo[pos]!=-1) return memo[pos];
	else{
		memo[pos] =  max(a[pos]+dp(a,cek,pos-2,memo),dp(a,cek,pos-1,memo));
		return memo[pos];
	}
}

int n,x;
long long a[100005];
bool cek[100005];
long long memo[100005];

int main(){
	cin>>n;
    int maxi = 0;
    memset(memo,-1,sizeof(memo));
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		cin>>x;
		a[x]+=x;
		cek[x] = 1;
		maxi = max(x,maxi);
	}
	cout<<dp(a,cek,maxi,memo)<<endl;


	return 0;
}
