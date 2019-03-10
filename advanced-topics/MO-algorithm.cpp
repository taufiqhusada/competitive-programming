// D-Query SPOJ

#include<bits/stdc++.h>
using namespace std;

#define MO 173

struct query
{
	int l,r,position;
};


int n,cntq;
int a[30005];
query q[200005];
int f[1000005];
int ans[200005];


bool cmp(query a, query b){
	if(a.l/MO != b.l/MO) {
		return a.l/MO < b.l/MO;
	}
	return a.r < b.r;
}

int res;

void add(int pos) {
	f[a[pos]]++;
	if(f[a[pos]] == 1) {
		res++;
	}
}

void remove(int pos) {
	f[a[pos]]--;
	if(f[a[pos]] == 0) {
		res--;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for (int i = 1; i<=n; ++i)cin>>a[i];
	cin>>cntq;
	for (int i = 1; i<=cntq; ++i){cin>>q[i].l>>q[i].r; q[i].position=i;}
	sort(q,q+cntq,cmp);
	int lNow = 1, rNow = 1;
	for (int i = 1; i<=cntq; ++i){
		int L = q[i].l, R = q[i].r;
		while(lNow<L){
			remove(lNow);
			lNow++;
		}
		while(lNow>L){
            lNow--;
			add(lNow);
		}
		while(rNow<=R){
			add(rNow);
			rNow++;
		}
		while(rNow>R+1){
            rNow--;
			remove(rNow);
		}
		ans[q[i].position] = res;
	}
	for (int i = 1; i<=cntq; ++i) cout<<ans[i]<<"\n";

}
