#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "nk" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int n, m;
int A[501][501];
int time[501][501];
pair<int,int> d[] = {{0,1},{1,0}};
//**Struct**//
struct block{
    int val, len;
}B[501][501];
//**Function**//
bool check(int x, int y){
    return (x > 0 && y > 0 && x <= n && y <= m);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> A[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    time[1][1] = 1; 
    while(q.size()){
        auto it = q.top(); q.pop();
        int x = it.fi;
        int y = it.se;
        for(int i = 0; i<2; i++){
            int u = x + d[i].if;
            int v = y + d[i].se;
            if(check[u][v]){
                time[u][v] = time[x][y] + 1;
                q.push({u,v});
            }
        }
    }
    
    return 0;
}
