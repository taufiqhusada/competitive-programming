#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[35],c[35],b,quan,sum;

int main(){
    cin>>n>>b;
    cin>>c[0];
    a[0] = 1;
    for (int i = 1; i<n; ++i){
        cin>>c[i];
        a[i] = a[i-1]<<1;
        c[i] = min(c[i],2*c[i-1]);
    }
    ll ans = (ll)4e18;
    for (int i = n-1; i>=0; --i){
        quan = b/a[i];
        b -= quan*a[i];
        sum+=c[i]*quan;
        if (b>0) ans = min(ans,sum+c[i]);
        else ans = min(ans,sum);
        if (b==0) break;
        //cout<<sum<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
