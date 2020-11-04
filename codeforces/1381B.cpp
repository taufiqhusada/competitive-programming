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

int x;
int maxi;
int cnt;
std::vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        maxi = -1;
        cnt = 1;
        for (int i = 0; i<2*n; ++i){
            cin>>x;
            if (i==0){
                maxi = x;
            }
            else if (x > maxi){
                v.pb(cnt);
                cnt = 1;
                maxi = x;
            }
            else{
                cnt++;
                if (i==2*n-1){
                    v.pb(cnt);
                }
            }
        }
        // for (int i =0; i<v.size(); ++i){
        //     cout<<v[i]<<endl;
        // }

        bool subset[v.size() + 1][n + 1];

        // If sum is 0, then answer is true
        for (int i = 0; i <= v.size(); i++)
            subset[i][0] = true;

        // If sum is not 0 and set is empty,
        // then answer is false
        for (int i = 1; i <= n; i++)
            subset[0][i] = false;

        // Fill the subset table in botton up manner
        for (int i = 1; i <= v.size(); i++) {
            for (int j = 1; j <= n; j++) {
                if (j < v[i - 1])
                    subset[i][j] = subset[i - 1][j];
                if (j >= v[i - 1])
                    subset[i][j] = subset[i - 1][j] || subset[i - 1][j - v[i - 1]];
            }
        }
        // cout<<solve(0,0)<<endl;
        if (subset[v.size()][n]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

        v.clear();
    }
}
