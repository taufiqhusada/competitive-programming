#include<bits/stdc++.h>
using namespace std;

long long val,n,s,x,lo,hi,mid,mini;

int main(){
    cin>>n>>s;
    lo = 0; hi = n;
    while(lo<=hi){
        mid = (lo+hi)/2;
        val = mid;
        string temp = to_string(mid);
        for (int i = 0; i<temp.length(); ++i){
            val-=(long long)(temp[i]-'0');
        }
        if (val>=s){
            mini = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    //cout<<mini<<endl;
    if (mini>0)cout<<n-mini+1<<endl;
    else cout<<0<<endl;
}
