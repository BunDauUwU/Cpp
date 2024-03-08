#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "LU" 
using namespace std;
//**Variable**//
int n, m;
int u, v, w;
vector<pair<int,int>> g[100005];
int h[100005];
int up[100005][21];
int mn[100005][21];
int mx[100005][21];
//**Struct**//

//**Function**//
void dfs(int u){
    for(auto it : g[u]){
        int v = it.fi;
        int w = it.se;
        if( v == up[u][0] )continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        mn[v][0] = w;
        mx[v][0] = w;
        dfs(v);
    }
}
void lca(int u, int v){
    int ansX = 0;
    int ansY = inf;
    if(h[u] < h[v])swap(u,v);
    int k = h[u] - h[v];
    for(int i = 0; (1<<i) <= k; i++){
        if((k >> i) & 1){
            ansX = max(ansX, mx[u][i]);
            ansY = min(ansY, mn[u][i]);
            u = up[u][i];
        }
    }
    if(u == v){
        cout<< u <<" ";
        cout<<ansY<<" "<<ansX<<"\n";
        return ;
    }
    k = log2(h[u]);
    for(int i = k; i>=0; i--){
        if(up[u][i] != up[v][i]){
            ansX = max(ansX, mx[u][i]);
            ansY = min(ansY, mn[u][i]);
            ansX = max(ansX, mx[v][i]);
            ansY = min(ansY, mn[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
        ansX = max(ansX, mx[u][0]);
        ansY = min(ansY, mn[u][0]);
        ansX = max(ansX, mx[v][0]);
        ansY = min(ansY, mn[v][0]);
    }
    // cout<< u <<" ";
    cout<<ansY<<" "<<ansX<<"\n";
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n;
    memset(mn,inf,sizeof(mn));
    for(int i = 1; i<n; i++){
    	cin >> u >> v >> w;
    	g[u].push_back({v,w});
    	g[v].push_back({u,w});
    }
    up[1][0] = 1;
    h[1] = 0;
    dfs(1);
    for(int i = 1; i <=20; i++){
        for(int u = 1; u<=n; u++){
            up[u][i] = up[up[u][i-1]][i-1];
            mn[u][i] = min(mn[u][i-1], mn[up[u][i-1]][i-1]);
            mx[u][i] = max(mx[u][i-1], mx[up[u][i-1]][i-1]);
        }
    }
    cin >> m;
    while(m--){
        cin >> u >> v;
        lca(u,v);

    }
    return 0;
}
