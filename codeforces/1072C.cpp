#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

ll a,b,cnta,cntb;

ll f(ll n){
    return n*(n+1)/2;
}

int main(){
    cin>>a>>b;
    vector<ll> resa;
    vector<ll> resb;
    ll lo = 0, hi = 9999999,mid, cnt, tot;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if (f(mid)<=a+b){
            cnt = mid;
            tot = f(mid);
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    bool visited[cnt+5];
    memset(visited,0,sizeof(visited));
    for (ll i = cnt; i>=1; i--){
        if (i<=a){
            cnta++;
            resa.pb(i);
            a-=i;
        }
        else{
            cntb++;
            resb.pb(i);
            b-=i;
        }
    }
    cout<<cnta<<endl;
    for (ll i = 0; i<resa.size(); ++i) cout<<resa[i]<<" ";
    cout<<endl;
    cout<<cntb<<endl;
    for (ll i = 0; i<resb.size(); ++i) cout<<resb[i]<<" ";
}
