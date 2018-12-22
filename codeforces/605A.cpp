#include<bits/stdc++.h>
using namespace std;

int n,cnt[100005],x,maxi;

int main(){
    cin>>n;
    for (int i = 0; i<n; ++i){
        cin>>x;
        cnt[x]+=cnt[x-1]+1;
        maxi = max(maxi,cnt[x]);
    }
    cout<<n-maxi<<endl;
}
