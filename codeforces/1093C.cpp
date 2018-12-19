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
int n;
ll b[200005],a[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>b[1];
    a[1] = 0;
    a[n] = b[1];
    for (int i = 2; i<=n/2; ++i) {
        cin>>b[i];
        if (b[i]<b[i-1]){
            a[i] = a[i-1];
            a[n-i+1] = b[i]-a[i-1];
        }
        else if (b[i]>b[i-1]){
            a[n-i+1] = a[n-i+2];
            a[i] = b[i] - a[n-i+2];
        }
        else{
            a[i] = a[i-1];
            a[n-i+1] = a[n-i+2];
        }
    }
    for (int i = 1; i<=n;++i)cout<<a[i]<<" ";
    cout<<endl;

}
