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

string s;
int n,a[30];
bool done[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.length();
    REP(i,n){
        a[s[i]-'a']++;
    }
    std::vector<int> v;
    REP(i,26){
        if (a[i]>0 && !done[a[i]]){
            v.pb(a[i]);
            done[a[i]] = 1;
        }
    }
    int cnt = 0,cnt2=0;
    if (v.size()>2){
        cout<<"NO"<<endl;
        return 0;
    }
    if (v.size()==1){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        sort(v.begin(),v.end());
        int maxi = v[1];
        int mini = v[0];
        REP(i,26){
            if (a[i]==maxi) cnt++;
            else if (a[i]==mini) cnt2++;
        }
        if (v[1]-v[0]>1){
            if (mini==1 && cnt2==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            return 0;
        }
        if (cnt>1) {
            if (cnt2==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}
