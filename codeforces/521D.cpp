#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int n,k,a[200005];
int cnt[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int ans = -1;
    int l = 1,r=200000, mid;
    while(l<=r){
        mid = (l+r)/2;
        int temp = 0;
        FOR(i,1,200000){
            temp += cnt[i]/mid;
        }
        if (temp>=k){
            ans = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    //cout<<ans<<endl;
    FOR(i,1,200000){
        if (k<=0) return 0;
        while(cnt[i]>=ans && k>0){
            cnt[i]-=ans;
            cout<<i<<" ";
            k--;
        }
    }

}
