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

int cnt[200005],jum[200005];
bool ada[200005];
int a[200005],n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    REP(i,n) cin>>a[i];
    sort(a,a+n);
    REP(i,n){
        int x = 0;
        while(a[i]>0){
            ada[a[i]] = true;
            if (jum[a[i]]<k){
                jum[a[i]]++;
                cnt[a[i]]+=x;
            }
            a[i]/=2;
            x++;
        }
        cnt[0]+=x;
        jum[0]++;
    }
    ada[0] = true;
    int mini = INF;
    REP(i,200005){
        if (ada[i] && jum[i]>=k){
            //cout<<i<<endl;
            mini = min(mini,cnt[i]);
        }
    }
    cout<<mini<<endl;
}
