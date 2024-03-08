#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "slime" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//
struct g{
	int v,c1,c2;
};
//**Variable**//
int n,s;
int a,b,c,d;
vector<g> adj[1000006];
int sum[1000006];
//**Function**//
void dfs(int u,int par){
	// cout<u<<" ";
	if(adj[u].size()>1){
		for(auto it:adj[u]){
			dfs(it.v,it.v);
			sum[u]+=sum[it.v];
		}
	}
	else{
		for(auto it:adj[u]){
			dfs(it.v,u);
			sum[u]+=sum[it.v];
		}
	}
	if(adj[u].size()==0){
		
	}
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>s;
    for(int i=1;i<=n;i++){
    	cin>>a>>b>>c>>d;
    	adj[a].push_back({b,c,d});
    }
  	dfs(1,1);
  	cout<<sum[1];
    return 0;
}
