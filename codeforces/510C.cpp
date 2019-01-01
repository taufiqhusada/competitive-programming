#include<bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define RESET(a,val)  memset(a,val,sizeof(a));
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef unsigned long long ull;

int n;
std::vector<vi> adj(105);
string s[105];
bool used[26];
int deg[105], cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    REP(i,n){
        cin>>s[i];
    }
    REP(i,n-1){
        if (s[i][0]==s[i+1][0]){
            int len = min(s[i].length(), s[i+1].length());
            int jj = 1;
            FOR(j, 1, len-1){
                if (s[i][j]!=s[i+1][j]){
                    adj[s[i][j]-'a'].pb(s[i+1][j]-'a');
                    deg[s[i+1][j]-'a']++;
                    used[s[i+1][j]-'a'] = true;
                    used[s[i][j]-'a'] = true;
                    break;
                }
                else {
                    jj++;
                    continue;
                }
            }
            //cout<<jj<<endl;
            if (jj==len){
                if (s[i].length()>s[i+1].length()){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
            }
        }
        else{
            adj[s[i][0]-'a'].pb(s[i+1][0]-'a');
            deg[s[i+1][0]-'a']++;
            used[s[i+1][0]-'a'] = true;
            used[s[i][0]-'a'] = true;
        }
    }
    REP(i,26){
        if (used[i]) cnt++;
    }
    int rail = 0;
    priority_queue<int> pq;
    REP(i,26){
        if (used[i]==true && deg[i] == 0){
            pq.push(i);
            rail++;
        }
    }

    vector<int> v;
    while(!pq.empty()){
        int u = pq.top();
        v.pb(u);
        pq.pop();
        REP(i, adj[u].size()){
            int v =adj[u][i];
            deg[v]--;
            if (deg[v]==0){
                 pq.push(v);
                 rail++;
             }
        }
    }
    if (rail!=cnt) cout<<"Impossible";
    else{
        REP(i,v.size()){
            cout<<(char)(v[i]+'a');
        }
        REP(i,26){
            if (!used[i]){
                cout<<(char)(i+'a');
            }
        }
    }
    cout<<endl;

}
