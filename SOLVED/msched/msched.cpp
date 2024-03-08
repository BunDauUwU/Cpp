#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "msched" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,m,x,y,ans=0,sum=0,pre=0;
int T[100005],vis[100005],tmp[100005];
vector<int> g[100005];
//**Function**//
void dfs(int u,int anc){
    for(auto v:g[u]){
        sum=0;
        dfs(v,anc);
        // vis[v]=1;
    }
    sum+=T[u];
    ans=max(sum,ans);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>T[i];tmp[i]=T[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sum=0;
        if(vis[i])continue;
        sum =0;
        dfs(i,i);
        if(g[i].size()>=2 && pre!=ans){
            ans+=T[i];
        }
        pre = ans;
    }
    cout<<ans;
    return 0;
}
