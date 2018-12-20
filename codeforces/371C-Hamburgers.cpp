#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string a;
int b,s,c,pb,ps,pc,needb,needs,needc;
ll r,ans,lo,hi,mid;

ll f(ll x){
    return max(1LL*0,needc*x-c)*pc + max(1LL*0,needs*x-s)*ps + max(1LL*0,needb*x-b)*pb;
}

int main(){
    cin>>a;
    for (int i = 0; i<a.length(); ++i){
        if (a[i]=='B')needb++;
        else if (a[i]=='S')needs++;
        else needc++;
    }
    cin>>b>>s>>c;
    cin>>pb>>ps>>pc>>r;
    lo = 0; hi = 11111111111111;
    while(lo<=hi){
        mid =(lo+hi)/2;
        if (f(mid)>r){
            hi = mid-1;
        }
        else{
            ans = mid;
            lo = mid+1;
        }
        //cout<<mid<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
