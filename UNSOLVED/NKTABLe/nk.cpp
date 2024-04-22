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
int res[501 + 501];
int timer;
int vis[501][501];
int traveled[501][501];
pair<int,int> d[] = {{0,1},{1,0}};
int uwu = 0;
//**Struct**//

//**Function**//
bool check(int x, int y){
    return (x > 0 && y > 0 && x <= n && y <= m && A[x][y] != 2);
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
    int hopli = 0;
    res[++timer] = A[1][1];
    queue<pair<int,int>> q1, q2;
    q1.push({n,m});vis[n][m] = 1;
    while(q1.size()){
        auto it = q1.front(); q1.pop();
        int x = it.fi;
        int y = it.se;
        for(int i = 0; i<2; i++){
            int u = x + - d[i].fi;
            int v = y + - d[i].se;
            if(check(u,v) && !vis[u][v]){
                q1.push({u,v});
                vis[u][v] = 1;
            }
        }
    }
    q1.push({1,1});
    for(int len = 2; len <= m + n - 1; len++){
        uwu = 0;
        while(q1.size()){
            auto it = q1.front(); q1.pop();
            int x = it.fi;
            int y = it.se;
            for(int i = 0; i < 2; i++){
                int u = x + d[i].fi;
                int v = y + d[i].se;
                if(check(u,v) &&  vis[u][v] && !traveled[u][v]){
                    if(u == n && v == m){
                        hopli = 1;
                    }
                    traveled[u][v] = 1;
                    uwu = max(uwu, A[u][v]);
                    q2.push({u,v});
                }
            }
        }
        res[++timer] = uwu;
        while(q2.size()){
            auto it = q2.front(); q2.pop();
            int x = it.fi;
            int y = it.se;
            // if(uwu == 1){
                // cout << x << ' ' << y << '\n';
            // }
            if(A[x][y] == uwu){
                q1.push({x,y});
            }
        }
    }
    for(int i = 1; i<=n+m-1; i++){
        cout<<res[i];
    }
    return 0;
}
