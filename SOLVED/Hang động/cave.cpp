#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "CAVE" 
using namespace std;
template<class X, class Y> bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0) ;}
template<class X, class Y> bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0) ;}
//**Variable**//
ll n;
ll A[100005];
ll B[100005];
ll val[100005][4];
ll u, v;
ll ans = -1e18;
vector<ll> g[100005];
//**Struct**//

//**Function**//
void dfs(ll u, ll par){
	val[u][B[u]] = max(val[u][B[u]], A[u]);
	if(B[u] == 3) ans = max(ans, val[u][B[u]]);
	for(auto v : g[u]){
		if(v!=par){
			dfs(v,u);
			for(ll i = 1; i<4; i++){
				for(ll j = 1; j<4; j++){
					if((i | j) == 3){
						ans = max(ans, val[v][i] + val[u][j]);
					}
				}
			}
			for(ll i = 1; i<4; i++){
				val[u][i] = max(val[u][i], val[v][i] + A[u]);
			}
		}
		if(B[u] != 0)for(ll i = 1; i<4; i++)if((i | B[u])==3) ans = max(ans, val[u][i]);
		
	}
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(ll i = 1; i<=n; i++){
    	cin>>A[i];
    }
    for(ll i = 1; i<=n; i++){
    	cin>>B[i];
    }
    for(ll i = 1; i<n; i++){
    	cin>>u>>v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 0; j<=4; j++){
            val[i][j] = -1e18;
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}