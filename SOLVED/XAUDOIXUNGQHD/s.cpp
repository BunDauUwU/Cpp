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
int n;
string s;
int dp[2001][2001];
int ans = 0;
bool res[2001];
//**Struct**//

//**Function**//
void check(int i, int j){
    if(dp[i][j] != 0)return;
            if(i == j){dp[i][j] = 1;return;}
            if(s[i-1] == s[j-1]){
                if(j-i == 1){
                    dp[i][j] = 2;
                    return;
                }
                if(dp[i+1][j-1] == 0)check(i+1,j-1);
                dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
            }
            else{
                if(dp[i + 1][j] == 0)check(i+1,j);
                if(dp[i][j-1] == 0)check(i,j-1);
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> s;
    for(int i = 0; i<s.size(); i++)res[i] = '0';
    n= s.size();
    s = s;
    for(int i = 1; i<n; i++){
        for(int j = i + 1; j<=n; j++){
            check(i,j);
            ans = max(ans,dp[i][j]);
        }
    }
    memset(res,0,sizeof(res));
    int i = 1;
    int j = n;
    while(i <= j)
            if(s[i-1] == s[j-1]){
                res[i] = 1;
                res[j] = 1;
                i++;
                j--;
            }else{
                if(dp[i][j] == dp[i+1][j])i++;
                else j--;
            }
        
    for(int i = 1; i<=n; i++){
        if(res[i]){
            cout<<s[i-1];                                                             
        }
    }
    // cout<<ans;
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
