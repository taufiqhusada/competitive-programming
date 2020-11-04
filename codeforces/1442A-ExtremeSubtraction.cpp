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

int t,n;
int mini, a[30005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for (int i= 0; i<n; ++i){
            cin>>a[i];
        }
        mini = a[0];
        bool valid = true;
        for (int i= 1; i<n-1; ++i){
            if (a[i] >= a[i-1] && a[i]>= a[i+1]){
                // cout<<i<<endl;
                int selisihkanan = a[i] - a[i+1];
                if (mini < selisihkanan){
                    valid = false;
                    break;
                }
                else{
                    a[i] = a[i+1];
                    mini -= selisihkanan;
                }
            }
            else{
                mini = min(a[i], mini);
            }
        }
        if (valid){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
