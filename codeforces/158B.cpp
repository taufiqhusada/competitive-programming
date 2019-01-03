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

int n,x;
int cnt[5],ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>x;
        cnt[x]++;
    }
    ans+=cnt[4];
    if (cnt[3]>cnt[1]){
        ans+=cnt[1];
        cnt[3]-=cnt[1];
        ans+=cnt[3];
        ans += cnt[2]/2;
        ans += cnt[2]%2;
    }
    else{
        ans+=cnt[3];
        cnt[1]-=cnt[3];
        ans+=cnt[2]/2;
        cnt[2] = cnt[2]%2;
        //cout<<ans<<endl;
        if (cnt[2]==1){
            if (cnt[1]>=2){
                cnt[1]-=2;
                ans+=1+cnt[1]/4 + (cnt[1]%4!=0);
            }
            else ans++;
        }
        else{
            ans+=cnt[1]/4 + (cnt[1]%4!=0);
        }
    }
    cout<<ans<<endl;
}
