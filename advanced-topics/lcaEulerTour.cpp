// SPOJ Lowest Common Ancestor

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

std::vector<int> euler;
std::vector<vi> adj(10015);
int fipos[44444];
int tree[444444];
int h[44444];
int n,m,q,t,cnt,a,b;

void dfs(int u, int p,int height){
    if(fipos[u]==-1) fipos[u] = euler.size();
    h[u] = height;
    euler.pb(u);
    REP(i,adj[u].size()){
        int v = adj[u][i];
        if (v!=p){
            dfs(v,u,height+1);
            euler.pb(u);
        }
    }
}

void build(int node,int l, int r){
    if(l==r){
        tree[node] = euler[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    int left = tree[node*2], right = tree[node*2+1];
    tree[node] = (h[left] < h[right]) ? left : right;
}

int query(int node, int b, int e, int L, int R) {
       if (b > R || e < L)
           return -1;
       if (b >= L && e <= R)
           return tree[node];
       int mid = (b + e) >> 1;

       int left = query(node << 1, b, mid, L, R);
       int right = query(node << 1 | 1, mid + 1, e, L, R);
       if (left == -1) return right;
       if (right == -1) return left;
       return h[left] < h[right] ? left : right;
   }

int tc;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    tc = 1;
    while(t--){
        cin>>n;
        euler.clear();
        for (int i = 1; i <= n; i++) adj[i].clear();
        FOR(i,1,n){
            cin>>m;
            REP(j,m){
                cin>>a;
                adj[i].pb(a);
                adj[a].pb(i);
            }
        }
        RESET(fipos,-1);
        RESET(h,0);
        RESET(tree,0);
        //cnt = 1;
        dfs(1,-1,1);
        /*REP(i,euler.size()){
            cout<<euler[i]<<" "<<h[euler[i]]<<endl;
        } cout<<endl;*/
        build(1,0,euler.size()-1);
        cin>>q;
        cout<<"Case "<<tc++<<":"<<endl;
        while(q--){
            cin>>a>>b;
            int left = fipos[a], right = fipos[b];
            //cout<<left<<" "<<right<<endl;
            if (left > right) swap(left, right);
            cout<<query(1, 0, euler.size()-1, left, right)<<endl;
        }
    }
}
