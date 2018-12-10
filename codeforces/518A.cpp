// Codeforces Round #293 (Div. 2) : A. Vitaly and Strings

#include<bits/stdc++.h>
using namespace std;

string s,t;

int main(){
	cin>>s>>t;
	int len = s.length();
	int cnt=0;
	for (int i = len-1; i>=0; --i){
		if (s[i]=='z') cnt++;
		else break;
	}
	string res = "";
	if (cnt>=0){
		for (int i = 0; i<len-cnt-1; i++){
			res+=s[i];
		}
		res+=(char)((int)s[len-cnt-1]+1);
		for (int i = len-cnt; i<len; ++i) res+='a';
	}
	else{
		for (int i = 0; i<len-1; ++i) res+=s[i];
		res+=(char)((int)s[len-1]+1);
	}
	if (res<t) cout<<res<<endl;
	else cout<<"No such string"<<endl;
	return 0;
}
