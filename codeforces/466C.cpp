#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,l,r;
ll a[500005],dp[500005],ans,tot,ss,ps;

int main(){
    cin>>n;
    for (int i = 1; i<=n; ++i){
        cin>>a[i];
        tot+=a[i];
    }
    if (tot%3==0)tot/=3;
    else{
        cout<<0<<endl;
        return 0;
    }
    for (int i = n; i>=1; --i){
        ss+=a[i];
        if (ss==tot) dp[i]=1;
    }
    for (int i= n; i>=1; --i){
        dp[i] += dp[i+1];
    }
    for (int i = 1; i<=n-2; ++i){
        ps +=a[i];
        if (ps==tot) ans+=dp[i+2];
    }
    cout<<ans<<endl;
}
