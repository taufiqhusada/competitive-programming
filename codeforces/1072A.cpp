#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

int w,h,k;
ll ans;

ll f(int i){
    return 2*(w-4*(i-1)) + 2*(h-4*(i-1)) - 4;
}

int main(){
    cin>>w>>h>>k;
    for (int i= 1; i<=k; ++i){
        ans+=f(i);
    }
    cout<<ans<<endl;
}
