#include<bits/stdc++.h>
using namespace std;

int cnt,k,n,a[300005],l,r,ansL,ansR;

int main(){
    cin>>n>>k;
    for (int i = 0; i<n; ++i) cin>>a[i];
    l = 0; r = 0;
    while(l<n && r<n){
        if (r<l){
            cnt = 0;
            r = l;
        }
        while (r < n) {
			if (cnt+!a[r] > k) break;
			cnt += !a[r];
			r++;
		}

		if (r - l > ansR - ansL)
			ansL = l, ansR = r;

		if (cnt > 0) cnt -= !a[l];
        l++;
    }
    cout<<ansR-ansL<<endl;
    for (int i = 0; i<ansL; ++i) cout<<a[i]<<" ";
    for (int i = ansL; i<ansR; ++i) cout<<1<<" ";
    for (int i = ansR; i<n; ++i) cout<<a[i]<<" ";

}
