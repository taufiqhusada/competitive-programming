#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

int allmask,allvisit,t,n,k;
double dp[4111][40];
int x[40],y[40],a[40];
string s;

double dis(int a,int b, int c, int d){
    return pow(((a-c)*(a-c)+(b-d)*(b-d)),0.5);
}

double solve(int mask, int pred){
    if (mask == allmask) return dis(x[pred],y[pred],0,0);
    if (dp[mask][pred]!=0) return dp[mask][pred];
    double ans = INF;
    for (int i = 1; i<=n; ++i){
        if (i!=pred){
            int newmask = mask|a[i];
            if (newmask!=mask){
                ans = min(ans, solve(newmask,i)+dis(x[i],y[i],x[pred],y[pred]));
            }
        }
    }
    return dp[mask][pred] = ans;

}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        allmask = (1<<k)-1;
        memset(dp,0,sizeof(dp));
        x[0] = 0;
        y[0] = 0;
        a[0] = 0;
        for (int i = 1; i<=n; ++i){
            cin>>x[i]>>y[i];
        }
        for (int i = 1; i<=n; ++i ){
            cin>>s;
            a[i] = stoi(s,nullptr,2);
        }
        double res = solve(0,0);
        if (res<INF)cout<<setprecision(13)<<res<<endl;
        else cout<<-1<<endl;
    }
}
