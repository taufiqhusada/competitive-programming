#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc = 1;
	while(cin>>n && n){
		int a,b,c;
		int dp[n][3];
		memset(dp,0,sizeof(dp));
		cin>>a>>b>>c;
		dp[0][0] = a;
		dp[0][1] = b;
		dp[0][2] = c+b;
		cin>>a>>b>>c;
		dp[1][0] = a+dp[0][1];
		dp[1][1] = b+min(dp[1][0],min(dp[0][1],dp[0][2]));
		dp[1][2] = c+min(dp[1][1],min(dp[0][1],dp[0][2]));
		for (int i = 2; i <n ; ++i)
		{
			cin>>a>>b>>c;
			dp[i][0] = a+min(dp[i-1][0],dp[i-1][1]);
			dp[i][1] = b+min(dp[i][0],min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2])));
			dp[i][2] = c+min(dp[i][1],min(dp[i-1][1],dp[i-1][2]));
		}
		cout<<tc<<". "<<dp[n-1][1]<<endl;
		tc++;
	}

	return 0;
}
