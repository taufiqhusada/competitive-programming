// Codeforces Round #316 (Div. 2) : C. Replacement
#include<bits/stdc++.h>
using namespace std;

#define t '.'
int n,m,x;
string s;
char c;
bool titik[300005];


int main(){
	cin>>n>>m;
	cin>>s;
	int q = 0;
	int len = 0;
	char prec = s[0];
	if (s[0]==t){
		len++; q++;
		titik[0]=1;
	}
	for (int i = 1; i<n; ++i){
		if (s[i]==t){
			if (prec!=t) q++;
			len++;
			titik[i] = 1;
		}
		prec = s[i];
	}

	while(m--){
		cin>>x>>c;
		x--;
		if (c!=t && titik[x]==1){
			titik[x] = 0;
			len--;
			if (x==0){
				if (titik[x+1]==0) q--;
			}
			else if (x==n-1){
				if (titik[x-1]==0) q--;
			}
			else{
				if (titik[x-1]==1 && titik[x+1]==1){
					q++;
				}
				else if (titik[x-1]==0 && titik[x+1]==0){
					q--;
				}
			}
		}
		else if (c==t && titik[x]==0){
			titik[x] = 1;
			len++;

			if (x==0){
				if (titik[x+1]==0) q++;
			}
			else if (x==n-1){
				if (titik[x-1]==0) q++;
			}
			else{
				if (titik[x-1]==0 && titik[x+1]==0){
					q++;
				}
				else if (titik[x-1]==1 && titik[x+1]==1){
					q--;
				}
			}

		}
		cout<<len-q<<endl;
	}

	return 0;
}
