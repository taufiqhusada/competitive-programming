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

int n, t;

void init(int dsu[], int n){
    REP(i,n){
        dsu[i] = i;
    }
}

int root(int dsu[], int u){
    while(dsu[u]!=u){
        u = dsu[u];
    }
    return u;
}

void join(int dsu[], int a, int b){
    dsu[root(dsu,a)] = root(dsu,b);
}

bool find(int dsu[], int a, int b){
    return root(dsu,a)==root(dsu,b);
}

string c;
string xx,yy;
string masukan;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int dsu[n+5];
        init(dsu,n);
        int benar = 0,salah = 0;
        while (getline(cin, masukan) && masukan[0] != '\0')
        {
            string temp = masukan;
            c = temp.substr(0, temp.find(" "));
            temp = temp.substr(temp.find(" ")+1);
            xx = temp.substr(0, temp.find(" "));
            yy = temp.substr(temp.find(" ")+1);
            int x = stoi(xx);
            int y = stoi(yy);
            if (c=="c") join(dsu,x,y);
            else {
                if(find(dsu,x,y)) benar++;
                else salah++;
            }
        }
        cout<<benar<<","<<salah;
        if (t) cout<<endl<<endl;
    }
}
