#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define INF 1e9
#define vi vector<int>

typedef long long ll;

int t,x;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>x;
        if (x%7==0) cout<<x/7<<endl;
        else cout<<x/7+1<<endl;
    }
}
