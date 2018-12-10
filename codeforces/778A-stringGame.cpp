// Codeforces Round #402 (Div. 1) : A. String Game

#include<bits/stdc++.h>
using namespace std;

string s,p;
int a[200005];

int main(){
	cin>>s>>p;
	int lens = s.length();
	int lenp = p.length();
	for (int i = 0; i< lens; ++i)
		cin>>a[i];
	int l = 0, h = lens, m,ans;
	while(l<h){
		m = (l+h)/2;
		string t = s;
		for(int i = 0; i<m; ++i)
			t[a[i]-1] = '.';
		int j = 0;
		int cnt = 0;
		for (int i = 0; i<lens; ++i){
			if (t[i]==p[j]){
				cnt++;
				j++;
			}
			if (cnt==lenp) break;
		}
		//cout<<l<<" "<<m<<" "<<h<<endl;
		if (cnt==lenp){
			ans = m;
			l = m+1;
		}
		else{
			h = m;
		}
	}
	cout<<ans<<endl;
	return 0;
}
