// Codeforces Round #526 (Div. 2) : C. The Fair Nut and String
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

string s;
int idx, a[100005];
ll ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    int n = s.length();
    char prec = 'b';
    char now;
    idx = -1;
    for (int i = 0; i<n; ++i){
        now = s[i];
        if (now=='a'){
            if (prec=='b'){
                idx++;
            }
            a[idx]++;
        }
        if (now=='a' || now =='b')prec = now;
    }

    ans = 1;
    for (int i = 0; i<=idx; ++i){
        ans*=(a[i]+1);
        ans%=MOD;
    }
    cout<<ans-1<<endl;

    return 0;
}
