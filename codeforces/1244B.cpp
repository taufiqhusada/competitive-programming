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

int t;
int n;
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        int kiri = -1, kanan = -1;;
        REP(i,n){
            if (s[i]=='1'){
                kiri = i;
                break;
            }
        }
        FORD(i,n-1,0){
            if (s[i]=='1'){
                kanan = i;
                break;
            }
        }
        if (kiri==-1 && kanan==-1){
            cout<<n<<endl;
        }
        else if (kiri==-1){
            cout<<2*(kanan+1)<<endl;
        }
        else if (kanan ==-1){
            cout<<(n-kiri)*2<<endl;
        }
        else{
            cout<<max(2*(kanan+1),(n-kiri)*2)<<endl;
        }

    }
}
