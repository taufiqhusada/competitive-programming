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

vector<int> height, euler, first, segtree;
vector<bool> visited;
int n;

void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto to : adj[node]) {
        if (!visited[to]) {
            dfs(adj, to, h + 1);
            euler.push_back(node);
        }
    }
}

void build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}

void LCA(vector<vector<int>> &adj, int root = 0) {
    n = adj.size();
    height.resize(n);
    first.resize(n);
    euler.reserve(n * 2);
    visited.assign(n, false);
    dfs(adj, root);
    int m = euler.size();
    segtree.resize(m * 4);
    build(1, 0, m - 1);
}

int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
        return -1;
    if (b >= L && e <= R)
        return segtree[node];
    int mid = (b + e) >> 1;

    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
}

int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right)
        swap(left, right);
    return query(1, 0, euler.size() - 1, left, right);
}

std::vector<vi> adj(200005);
int q,m,a,b,c;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m;
    REP(i,m-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    LCA(adj,1);
    cin>>q;
    while(q--){
        cin>>a>>b>>c;
        int lca1 = lca(a,b);
        int lca2 = lca(a,c);
        int lca3 = lca(b,c);
        //cout<<lca1<<" "<<lca2<<" "<<lca3<<endl;
        int lcaFix;
        if (height[lca1]>height[lca2]){
            if (height[lca3]>height[lca1]){
                lcaFix = lca3;
            }
            else lcaFix = lca1;
        }
        else{
            if (height[lca3]>height[lca2]){
                lcaFix = lca3;
            }
            else lcaFix = lca2;
        }
        cout<<lcaFix<<endl;
    }
}
