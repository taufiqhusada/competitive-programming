#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 998244353


int t,n,k;
int a[200005], b[200005];
bool availInB[200005];

int main(){
    cin>>t;
    while(t--){
        map<int, int> m;
        cin>>n>>k;
        for (int i =0; i<n; ++i){
            cin>>a[i];
            availInB[a[i]] = false;
            m[a[i]] = i;
        }
        for (int i = 0; i<k; ++i){
            cin>>b[i];
            availInB[b[i]] = true;

        }

        bool valid = true;
        ll ans = 1;
        for (int j = 0; j<k; ++j){
            int i = m[b[j]];

            if (availInB[a[i]]){
                if (i==0){
                    if (availInB[a[i+1]]){
                        valid  = false;
                        break;
                    }
                    else{
                        availInB[a[i]] = false;
                    }
                }
                else if (i==n-1){
                    if (availInB[a[i-1]]){
                        valid  = false;
                        break;
                    }
                    else{
                        availInB[a[i]] = false;
                    }
                }
                else{
                    if (availInB[a[i-1]] && availInB[a[i+1]]){
                        valid = false;
                        break;
                    }
                    else{
                        availInB[a[i]] = false;
                        if (!availInB[a[i-1]] && !availInB[a[i+1]]){
                            ans *= 2;
                            ans %= MOD;

                        }
                    }
                }
            }
            // cout<<i<<" "<<ans<<endl;
        }
        if (valid){
            cout<<ans%MOD<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
}
