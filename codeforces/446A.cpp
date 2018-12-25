#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;
ll a[100005];
int l[100005],r[100005],ans;

int main(){
    cin>>n;
    cin>>a[0];
    l[0] = 1;
    for (int i = 1; i<n; ++i){
        cin>>a[i];
        if (a[i]>a[i-1]) l[i]+=l[i-1]+1;
        else l[i] = 1;
    }
    r[n-1] = 1;
    for (int i = n-2; i>=0; --i){
        if(a[i]<a[i+1]) r[i]+=r[i+1]+1;
        else r[i] = 1;
    }
    ans = 1;
    for (int i =1; i<n-1; ++i){
        if (a[i-1]+1<a[i+1])ans=max(ans,1+l[i-1]+r[i+1]);
    }
    cout<<max(ans,max(max(r[0],l[n-1]),max(l[n-2]+1,r[1]+1)))<<endl;

    #ifdef LocalHost
    	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
    #endif
}
