#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define pii pair<int,int>
#define RESET(a,val) memset(a,val,sizeof(a))

typedef long long ll;

int cnt[100005],res;

int a,b,n;
ll s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i = 0; i<n-1; ++i){
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    if (n==2) {cout<<s<<endl; return 0;}
    for (int i = 1; i<=n; ++i){
        if (cnt[i]==1) res++;
    }
    cout<<setprecision(16)<<(s*1./res)*2<<endl;

}
