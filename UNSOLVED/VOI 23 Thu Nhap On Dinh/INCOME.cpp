#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define FILE "INCOME" 
// #define cout cerr
using namespace std;
//**Variable**//
int n;

int A[500005];
int l[500005], r[500005];
int T[500005]; 
vector<pair<int,int>> g[6*500005];
int idx[6*500005];
int d[6*500005];
int vis[6*500005];
int ans[6*500005];
int order[6*500005];
int label[6*500005];
//**Struct**//

//**Function**//
int build(int id, int l, int r){
	if(l == r){idx[l] = id; T[id] = A[l];return id;}
	int mid = (l + r) / 2;
	int lft = build(id*2,l,mid);
	int rht = build(id*2+1,mid+1,r);
	g[id*2].push_back({id,0});
	g[id*2+1].push_back({id,0});
	T[id] = max(T[id*2],T[id*2+1]);
	return max(lft, rht);
}
void merge(int id, int l, int r, int u, int v, int tar){
	if(r < l || v < u || r < u || v < l)return ;
	if(u <= l && r <= v){
		g[id].push_back({idx[tar],1});
		return void();
	}
	int mid = (l+r) / 2;
	merge(id*2, l, mid, u, v, tar);
	merge(id*2+1, mid + 1, r, u, v, tar);
}
int bfs(int s){
	int mx = 0;
	d[s] = 0;
	vis[s] = 1;
	label[s] = s;
	set<pair<int,int>> q;
	q.insert({d[s],s});
	while(q.size()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(auto [v,w] : g[u]){
			if(d[u] + w < d[v] && label[v] != s && !vis[v]){
				vis[v] = 1;
				q.erase({d[v],v});
				d[v] = d[u] + w;
				mx = max(mx, d[v]);
				label[v] = s;
				q.insert({d[v],v});
			}
		}
	}
	return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n;
    for(int i = 1; i<=n; i++)cin >> A[i];
   	iota(order + 1, order + 1 + n, 1);
    sort(order + 1, order + 1 + n, [&](int i, int j){return A[i] > A[j];});
    int ed = build(1,1,n);
    for(int i = 1; i<=n; i++){
    	cin>>l[i]>>r[i];
    	merge(1,1,n,l[i],r[i],i);
    }
    int mx = 0;
    memset(d,inf,sizeof(d));
    for(int i = 1; i<=n; i++){
    	if(label[idx[order[i]]] != idx[order[i]] && !vis[idx[order[i]]]){
    		mx = max(bfs(idx[order[i]]) + 1,mx);
    	}
    }
  	cout<<mx;
    return 0;
}
