#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 998244353;
#define maxn 120000
LL f[4][maxn], a[maxn];
char s[maxn];
int main(){
	int n;
	cin >> n >> s + 1;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1){
		f[0][i] = f[0][i - 1] + a[i] * (s[i] == 'h');
		f[1][i] = min(f[0][i], f[1][i - 1] + a[i] * (s[i] == 'a'));
		f[2][i] = min(f[1][i], f[2][i - 1] + a[i] * (s[i] == 'r'));
		f[3][i] = min(f[2][i], f[3][i - 1] + a[i] * (s[i] == 'd'));
	}
	cout << min(min(f[0][n], f[1][n]), min(f[2][n], f[3][n]));
}
