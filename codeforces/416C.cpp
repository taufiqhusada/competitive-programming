#include<bits/stdc++.h>
using namespace std;

struct group{
    int tot, pay, index;
}chair[1005],a[1005];

bool cmp(group a, group b){
    return a.pay>b.pay;
}
bool cmp2(group a, group b){
    return a.tot<b.tot;
}

int n,m,ans,pos,cnt;
bool visited[1005];
std::vector<pair<int,int> > v;

int main(){
    cin>>n;
    for (int i = 0; i<n; ++i){
        cin>>a[i].tot>>a[i].pay;
        a[i].index=i;
    }
    sort(a,a+n,cmp);
    cin>>m;
    for (int i = 0; i<m; ++i){
        cin>>chair[i].tot;
        chair[i].index = i;
    }
    sort(chair,chair+m,cmp2);
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j)
            if ( a[i].tot<=chair[j].tot&& visited[chair[j].index]==false){
                cnt++;
                visited[chair[j].index] = true;
                v.push_back(make_pair(a[i].index,chair[j].index));
                ans+=a[i].pay;
                break;
            }
    }
    cout<<cnt<<" "<<ans<<endl;
    for (int i = 0; i<v.size(); ++i){
        cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
    }
}
