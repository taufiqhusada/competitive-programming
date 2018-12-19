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

string s;
int t,batas;
bool cek,cek2;
int let[26];
int dif;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        memset(let,0,sizeof(let));
        cek = false; cek2 = false;
        cin>>s;
        if (s.length()&1){
            batas = s.length()/2;
        } else batas = s.length()/2-1;
        for (int i = 0; i<=batas; ++i){
            if (s[i]!=s[s.length()-1-i]){
                cout<<s<<endl;
                cek = true;
                break;
            }
        }

        if (cek==false){
            string temp = "";
            for (int i = 0; i<s.length(); ++i){
                let[(int)s[i]-(int)'a']++;
            }
            for (int i=0; i<26; ++i){
                for (int j = 0; j<let[i]; ++j){
                    temp+=(char)(i+'a');
                }
            }
            for (int i = 0; i<=batas; ++i){
                if (temp[i]!=temp[s.length()-1-i]){
                    cek2 = true;
                    break;
                }
            }
            if (cek2==false) cout<<-1<<endl;
            else cout<<temp<<endl;
        }
    }
}
