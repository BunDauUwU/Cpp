#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "uwu" 
using namespace std;
//**Variable**//
int n, m;
int s[11][10001];
int F[11][10001];
int dp[10001];
int k;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            cin>>s[i][j];
            F[i][s[i][j]] = j;
        }
    }
    int miss = 0;
    int ans = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = 1;
        for(int j = i - 1; j>=1; j--){
            int tmp = s[1][j];
            miss = 0;
            for(k = 2; k<=m; k++){
                if(F[k][s[1][i]] < F[k][tmp]){
                    miss = 1;
                    break;
                }
            }
            if(!miss){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans;
    return 0;
}













// #include <bits/stdc++.h>
// #define ll long long
// #define ld long double 
// #define inf 0x3f3f3f3f
// #define fi first
// #define se second
// //#define cout cerr
// #define FILE "uwu" 
// using namespace std;
// //**Variable**//
// int n,m;
// int u, v, w;
// vector<pair<int,int>> g[100001];
// char t;
// int k;
// int h[100001], sz[100001];
// int chainHead[100001];
// int chainPos[100001];
// int timer = 0;
// int BEGIN[100001];
// int END[100001];
// int res[100001];
// //**Struct**//
// struct Edge{
//     int u, v, w;
// }E[100001];
// struct inp{
//     int u, v, w, id;
//     int type;
// }query[100001];
// //**Function**//
// void DFS(int u, int p){
//     BEGIN[u] = timer ++;
//     h[u] = h[p] + 1;
//     sz[u] = 1;
//     for(auto it : g[u]){
//         int e = it.fi, w = it.se;
//         if( e == p )continue;
//         DFS(v,u);
//         END[u] = timer ++;
//         sz[u] = sz[v] + 1;
//     }
// }


// void HLD(int u, int p, int head){
//     chainHead[u] = head;
//     chainPos[u] = timer ++;

//     int nxt = -1; 
//     for(auto it : g[u]){
//         int v = it.fi, w = it.se; 
//         if((nxt == -1 || sz[v] >= sz[nxt]) && nxt != p){
//             nxt = v;
//         }
//     }
//     if(nxt != - 1) HLD(v,u,head);
//     for(auto it :g[u]){
//         int v = it.fi, w = it.se;
//         if(v != nxt && v!=p){
//             HLD(v,u,u);
//         }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);
//     // freopen(FILE".inp","w",stdout);
//     freopen(FILE".inp","r",stdin);
//     freopen(FILE".out","w",stdout);
//     cin>>n>>m;
//     for(int i = 1; i<n; i++){
//         cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//         E[i] = {u,v,w};
//         query[i] = {u,v,w, 0, -1};                                                      
//     }
//     timer = 0;
//     DFS(1,1);
//     timer = 0;
//     HLD(1,1,1);
//     for(int i = n + 1; i<=n + m; i++){
//         cin>>t;
//         if(t == 'P'){
//             cin >> u >> v >> k;
//             query[i] = {u,v,k,i-n,0};
//         }else{
//             cin >> u >> k;
//             query[i] = {E[i].u,E[i].v,k,i-n,1};
//         }
//     }
//     timer = 0;
//     for(int i = 1; i<= n + m; i++){

//     }
//     return 0;
// }
