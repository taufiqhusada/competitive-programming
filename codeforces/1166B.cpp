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

int k,n,m;
char v[]={'a','e','i','o','u'};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k;
    //int cnt = 0;
    FOR(i,5,k-1){
        if (k%i==0){
            //cout<<i<<endl;
            n = i;
            m = k/i;
            if ((n>=5)&&(m>=5)){
                REP(row,m){
                    FOR(j,row%5,n+row%5-1){
                        cout<<v[j%5];
                        //cnt++;
                    }
                }
                //cout<<cnt<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
