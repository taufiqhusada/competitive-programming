// Codeforces Round #394 (Div. 2) : C. Dasha and Password

#include<bits/stdc++.h>
using namespace std;

bool adaNum[55], adaSym[55], adaLet[55];
int nearNum[55], nearLet[55], nearSym[55], temp,n,m;
string s[55];

bool cekNum(char a){
    if ((int)a>=48 && (int)a<=57 ) return true;
    else return false;
}

bool cekLet(char a){
    if ((int)a>=97 && (int)a<=122 ) return true;
    else return false;
}

int main(){
    cin>>n>>m;
    for (int i = 0; i<n; ++i){
        cin>>s[i];
        nearLet[i] = m+5; nearNum[i] = m+5;nearSym[i] = m+5;
        for (int j = 0; j<m; ++j){
            if (cekNum(s[i][j])) {
                adaNum[i] = 1;
                if (j>=m/2+1) temp = m-j;
                else temp = j;
                nearNum[i] = min(temp,nearNum[i]);
            }
            else if (cekLet(s[i][j])){
                 adaLet[i] = 1;
                 if (j>=m/2+1) temp = m-j;
                 else temp = j;
                 nearLet[i] = min(temp,nearLet[i]);
            }
            else {
                adaSym[i] = 1;
                if (j>=m/2+1) temp = m-j;
                else temp = j;
                nearSym[i] = min(temp,nearSym[i]);
            }
        }
        //cout<<nearNum[i]<<" "<<nearLet[i]<<" "<<nearSym[i]<<endl;
    }
    int ans = 555555;
    for (int i = 0; i<n-2; ++i){
        for (int j = i+1; j<n-1; ++j){
            for (int k = i+2; k<n; ++k){
                if (adaLet[i] && adaNum[j] && adaSym[k]) ans= min(ans,nearLet[i]+nearNum[j]+nearSym[k]);
                if (adaLet[j] && adaNum[i] && adaSym[k]) ans= min(ans,nearLet[j]+nearNum[i]+nearSym[k]);
                if (adaLet[j] && adaNum[k] && adaSym[i]) ans= min(ans,nearLet[j]+nearNum[k]+nearSym[i]);
                if (adaLet[i] && adaNum[k] && adaSym[j]) ans= min(ans,nearLet[i]+nearNum[k]+nearSym[j]);
                if (adaLet[k] && adaNum[j] && adaSym[i]) ans= min(ans,nearLet[k]+nearNum[j]+nearSym[i]);
                if (adaLet[k] && adaNum[i] && adaSym[j]) ans= min(ans,nearLet[k]+nearNum[i]+nearSym[j]);
            }
        }
    }
    cout<<ans<<endl;

}
