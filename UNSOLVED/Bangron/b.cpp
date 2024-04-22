	#include <bits/stdc++.h>
	#define ll long long
	#define ld long double 
	#define inf 0x3f3f3f3f
	#define fi first
	#define se second
	//#define cout cerr
	#define FILE "b" 
	template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
	template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
	using namespace std;
	//**Variable**//
	int n, m, k;
	int u, v;
	vector<int> g[100005];
	pair<int,int> p[100005];
	int cnt[100005];
	int vis[100005];
	//**Struct**//

	//**Function**//
	int main()
	{
	    ios_base::sync_with_stdio(false);cin.tie(NULL);
	    // freopen(FILE".inp","w",stdout);
	    freopen(FILE".inp","r",stdin);
	    freopen(FILE".out","w",stdout);
	    cin >> n >> m >> k;
	    for(int i = 1; i<=m; i++){
	    	cin >> u >> v;
	    	g[u].push_back(v);
	    	g[v].push_back(u);
	    }
	    for(int i = 1; i<=n; i++){
	    	p[i] = {g[i].size() + 1, i};
	    }
	    priority_queue<pair<int,int>> q;
	    for(int i = 1; i<=n; i++){
	    	q.push(p[i]);
	    }
	    ll ans = 0;
	    while(q.size() && k--){
	    	auto it = q.top(); q.pop();
	    	int u = it.se;
	    	if(cnt[u] != 0){
	    		it.fi = it.fi - cnt[u];
	    		cnt[u] = 0;
	    		q.push(it);
	    		continue;
	    	}
	    	vis[u] = 1;
	    	ans += it.fi;
	    	for(auto v : g[u]){
	    		if(!vis[v]){
	    			cnt[u]++;
	    			vis[v] = 1;
	    		}
	    	}
	    	for(auto v : g[u]){
	    		for(auto w: g[v]){
	    			if(vis[w]) 
	    				cnt[v]++;
	    		}
	    	}
	    }
	    cout << ans;
	    return 0;
	}
