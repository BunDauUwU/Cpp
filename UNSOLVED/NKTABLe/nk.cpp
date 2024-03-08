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
int ans[501][501];
int len[501][501];
pair<int,int> D[] = {{1,0},{0,1}};
//**Struct**//

//**Function**//
bool check(int x, int y){
	return (x > 0 && x <= n && y > 0 && y <= m && A[x][y] != 2);
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
    queue<pair<int,int>> q2;
    q.push({1,1});
    ans[1][1] = A[1][1];
    len[1][1] = 1;
    	while(q.size()){
    		auto it = q.front();q.pop();
    		int x = it.fi; 
    		int y = it.se;
    		for(int i = 0; i<2; i++){
    			int u = x + D[i].fi;
    			int v = y + D[i].se;
    			if(check(u,v)){
    			}
    		}
    	}
    while(ans[n][m]){
    	cout<<ans[n][m]%2;
    	ans[n][m]/=2;
    }
    return 0;
}
