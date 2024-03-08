#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "golf" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int n, m;
int cur = 0, total = 0; 
int C[501][501];
int hole[501][501];
int vis[501][501];
pair<int,int> d[] = {{0,-1},{0,1},{-1,0},{1,0}};
pair<int,int> st;
//**Struct**//

//**Function**//
bool check(int x, int y){
	return (x > 0 && x <= n && y > 0 && y<=m && !vis[x][y]);
}
bool solve(int D){
	cur = 0;
	memset(vis, 0, sizeof(vis));
	queue<pair<int,int>> q;
	q.push(st);
	vis[st.fi][st.se] = 0;
	while(q.size()){
		auto it = q.front();q.pop();
		int x = it.fi, y = it.se;
		for(int i = 0; i<4; i++){
			int u = x + d[i].fi;
			int v = y + d[i].se;
			if(check(u,v) && abs(C[x][y] - C[u][v]) <= D){
				if(hole[u][v])cur++;
				vis[u][v] = 1;
				if(cur == total){
					return true;
				}
				q.push({u,v});
			}
		}
	}
	if(cur == total){
		return true;
	}
	return false;
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
    		cin >> C[i][j];
    	}
    }
    for(int i = 1; i<=n; i++){
    	for(int j = 1; j<=m; j++){
    		cin >> hole[i][j];
    		if(hole[i][j]){
    			st = {i,j};
    			total++;
    		}
    	}
    }
    int l = 1, r = 1e9;
    int mid;
    while(l <= r){
    	mid = (l + r)/2;
    	if(solve(mid)){
    		r = mid-1;
    	}else{
    		l = mid+1;
    	}
    }
    cout<<l;
    return 0;
}
