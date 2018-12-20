#include<bits/stdc++.h>
using namespace std;

int n,m,a[1005],b[1005],c[1005],d[1005];
long long memo[1005][1005];

long long dp(int pos, int dough){
    if (dough<=0 || pos<0) return 0;
    if (memo[pos][dough]==-1){
        int i = 0;
        while(b[pos]*i<=a[pos] && c[pos]*i<=dough){
            memo[pos][dough] = max(memo[pos][dough],dp(pos-1,dough-c[pos]*i)+1LL*d[pos]*i);
            i++;
        }
    }
    return memo[pos][dough];
}

int main(){
    cin>>n>>m>>c[0]>>d[0];
    b[0] = 0;
    a[0] = n;
    memset(memo,-1,sizeof(memo));
    for (int i = 1; i<=m; ++i){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    cout<<dp(m,a[0])<<endl;
}
