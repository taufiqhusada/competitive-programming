#include<bits/stdc++.h>
using namespace std;

int n,q,m,re,x;
char c,t;
string s;
int dp[30][2000];

int main(){
    cin>>n;
    cin>>s;
    int len = s.length();
    for (int i = 0; i<26; ++i){
        for (int j = 0; j<len; ++j){
            re = 0;
            for (int k = j; k<len; ++k){
                if (s[k]!=(char)(i+(int)'a'))re++;
                dp[i][re] = max(dp[i][re],k-j+1);
            }
        }
        for (int re  = 1; re<=n; ++re){
            dp[i][re] = max(dp[i][re],dp[i][re-1]);
        }
    }
    cin>>q;
    while(q--){
        cin>>x>>t;
        cout<<dp[(int)((int)t-'a')][x]<<endl;
    }
}
