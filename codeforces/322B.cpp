// Codeforces Round #190 (Div. 2) : B. Ciel and Flowers

#include<bits/stdc++.h>
using namespace std;

long long ans,r,g,b,temp;

int main(){
    cin>>r>>g>>b;
    ans = -1;
    for (int i = 0; i<3; ++i){
        if (i>r || i>g || i>b){
            if (i<=r) temp = (r-i)/3;
            if (i<=g) temp = (g-i)/3;
            if (i<=b) temp = (b-i)/3;
        }
        else{
            temp = i + (r-i)/3 + (g-i)/3 + (b-i)/3;
        }
        ans = max(temp,ans);
    }
    cout<<ans<<endl;

}
