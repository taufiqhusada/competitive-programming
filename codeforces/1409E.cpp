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

int t,n,k;
int a[200005];

int x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        for (int i=0; i<n; ++i){
            cin>>a[i];
        }
        for (int i = 0; i<n; ++i){
            cin>>x;
        }
        sort(a, a+n);
        int dpR[200005];
        int dpL[200005];
        RESET(dpR, 0);
        RESET(dpL, 0);
        int j = n-1;
        for (int i= n-1; i>=0; --i){
            while(a[j]-a[i] > k) j--;
            dpR[i] = j-i+1;
            if (i != n-1){
                dpR[i] = max(dpR[i], dpR[i+1]);
            }
        }

        j = 0;
        for (int i =0; i<n; ++i){
            while(a[i] - a[j] > k) j++;
            dpL[i] = i - j + 1;
            if (i!=0){
                dpL[i] = max(dpL[i], dpL[i-1]);
            }
        }

        int ans =1;
        for (int i =0; i<n-1; ++i){
            ans = max(ans, dpL[i] + dpR[i+1]);
        }
        cout<<ans<<endl;

    }
}
