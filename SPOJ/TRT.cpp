// TRT - Treats for the Cows
// Dp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp(int arr[], int a,int lo, int hi, ll memo[2001][2001]){
	if (memo[lo][hi]!=-1){
		return memo[lo][hi];
	}
	if (lo == hi){
		memo[lo][hi] = a*arr[lo];
		return memo[lo][hi];
	}
	else{
		memo[lo][hi]=  max(arr[lo]*a+dp(arr,a+1,lo+1,hi,memo),arr[hi]*a+dp(arr,a+1,lo,hi-1,memo));
		return memo[lo][hi];
	}
}

int n,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int arr[n];
	for (int i =0; i<n; i++){
		cin>>arr[i];
	}
	ll memo[2001][2001];
	memset(memo,-1,sizeof(memo));
	cout<<dp(arr,1,0,n-1,memo)<<endl;

	return 0;
}
