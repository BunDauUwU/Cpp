#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "uwu" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int n, m;
int timer = 0;
int g[1505][1505];
int vis[1505][1505];
pair<int,int> swan[3];
//**Struct**//

//**Function**//
bool check(int x, int y){
	return (x > 0 && x < n + 1 && y > 0 && y < m + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
   	cin >> n >> m;
   	queue<pair<int,int>> q;
   	for(int i = 1; i<=n; i++){
   		for(int j = 1; j<=m; j++){
   			char c;
   			cin >> c;
   			if( c == '.'){
   				g[i][j] = 0;
   				q.push({i,j});
   			}
   			if( c == 'L'){
   				g[i][j] = 0;
   				swan[++timer] = {i,j};
   				q.push({i,j});
   			}
   			if( c == 'X'){
   				g[i][j] = -1;
   			}
   		}
   	}

   	while(q.size()){
   			auto it = q.front(); int x = it.fi; int y = it.se;q.pop();
   			if(check(x + 1, y) && g[x+1][y] == -1){
   				g[x+1][y] = g[x][y] + 1;
   				q.push({x+1,y});
   			}
   			if(check(x - 1, y) && g[x-1][y] == -1){
   				g[x-1][y] = g[x][y] + 1;
   				q.push({x-1,y});
   			}
   			if(check(x, y - 1) && g[x][y-1] == -1){
   				g[x][y-1] = g[x][y] + 1;
   				q.push({x,y-1});
   			}
   			if(check(x, y + 1) && g[x][y+1] == -1){
   				g[x][y+1] = g[x][y] + 1;
   				q.push({x,y+1});
   			}
   	}
   	
   	queue<pair<int,int>> A, trace;
   	A.push(swan[1]);
   	vis[swan[1].fi][swan[1].se] = 1;
   	// cout<<swan[1].fi<<" "<<swan[1].se;
   	// return 0;
   	int day = 0;
   	for(; day<=n*m; day++){
   		while(A.size()){
   			auto it  = A.front(); int x = it.fi; int y = it.se;A.pop();
   			trace.push({x,y});
   			if(check(x + 1, y) && g[x+1][y] <= day && !vis[x+1][y]){
   				A.push({x+1,y});
   				vis[x+1][y] = 1;
   			}
   			if(check(x - 1, y) && g[x-1][y] <= day && !vis[x-1][y]){
   				A.push({x-1,y});
   				vis[x-1][y] = 1;
   			}
   			if(check(x, y - 1) && g[x][y-1] <= day && !vis[x][y-1]){
   				A.push({x,y-1});
   				vis[x][y-1] = 1;
   			}
   			if(check(x, y + 1) && g[x][y+1] <= day && !vis[x][y+1]){
   				A.push({x,y+1});
   				vis[x][y+1] = 1;
   			}
   		}
   		while(trace.size()){
   			auto it  = trace.front(); int x = it.fi; int y = it.se;trace.pop();
   			if(it == swan[2]){
   				cout<<day;
   				return 0;
   			}
   			if(check(x + 1, y) && g[x+1][y] <= day + 1 && !vis[x+1][y]){
   				A.push({x+1,y});
   				vis[x+1][y] = 1;
   			}
   			if(check(x - 1, y) && g[x-1][y] <= day + 1 && !vis[x-1][y]){
   				A.push({x-1,y});
   				vis[x-1][y] = 1;
   			}
   			if(check(x, y - 1) && g[x][y-1] <= day + 1 && !vis[x][y-1]){
   				A.push({x,y-1});
   				vis[x][y-1] = 1;
   			}
   			if(check(x, y + 1) && g[x][y+1] <= day + 1 && !vis[x][y+1]){
   				A.push({x,y+1});
   				vis[x][y+1] = 1;
   			}
   		}
   	}
   	cout << day;
    return 0;
}
