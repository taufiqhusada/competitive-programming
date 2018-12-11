// Codeforces Round #526 (Div. 2) : A - The Fair Nut and Elevator

#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int now;
    int res[n+1], a[n+1];
    memset(res,0,sizeof(res));
    for (int i = 1; i<=n; ++i) cin>>a[i];
    for (int x = 1; x<=n; ++x){
        for (int i = 1; i<=n; ++i){
            res[x]+=2*a[i]*(abs(i-x)+abs(i-1)+abs(x-1));
        }
    }
    int ans = INT_MAX;
    for (int x = 1; x<=n; ++x) ans = min(ans, res[x]);
    cout<<ans<<endl;

    return 0;
}
