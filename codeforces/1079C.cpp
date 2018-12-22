#include<bits/stdc++.h>
using namespace std;

int n,a[200005],dp[200005][7],last;
std::vector<int> v;

int main(){
    cin>>n;
    cin>>a[0];
    dp[0][1] = 1;
    dp[0][2] = 1;
    dp[0][3] = 1;
    dp[0][4] = 1;
    dp[0][5] = 1;
    for (int i = 1; i<n; ++i){
        cin>>a[i];
        for (int j = 1; j<=5; ++j){
            if (a[i]>a[i-1]){
                for (int p = j-1; p>=1; --p){
                    if (dp[i-1][p]!=0) dp[i][j] = p;
                }
            }
            if (a[i]<a[i-1]){
                for (int p = j+1; p<=5; ++p){
                    if (dp[i-1][p]!=0)dp[i][j] = p;
                }
            }
            if (a[i]==a[i-1]){
                for (int p = 1; p<=5; ++p){
                    if (dp[i-1][p]!=0 && p!=j)dp[i][j] = p;
                }
            }
        }
    }
    for (int i= 1; i<=5; ++i){
        if (dp[n-1][i]!=0) last = i;
    }
    if (last==0) cout<<-1<<endl;
    else{
        for (int i = n-1; i>=0; --i){
            v.push_back(last);
            last = dp[i][last];
        }
    }
    for (int i = v.size()-1; i>=0; --i){
        cout<<v[i]<<" ";
    }
}
