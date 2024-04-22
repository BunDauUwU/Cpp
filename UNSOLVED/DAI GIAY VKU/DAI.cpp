#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "DAI" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
ll n, k;
ll l[51], r[51];
ll dp[500005];
ll mod = 1e9 + 7;
//**Struct**//
struct Node{
	ll val, lz;
}T[4*500005];
//**Function**//
void lz(int id){
	ll val = T[id].lz;
	if(val){
		T[id*2].val += val;
		T[id*2+1].val += val;
		T[id*2].lz += val;
		T[id*2+1].lz += val;
		T[id].lz = 0;
	}
}
void update(int id, int l, int r, int u, int v, ll val){
	lz(id);
	if(l > v || u > r)return ;
	if(u <= l && r <= v){
		T[id].val += val;
		T[id].lz += val;
		return;
	}
	int mid = (l + r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	T[id].val = (T[id*2].val + T[id*2+1].val)%mod;
}
ll get(int id, int l, int r, int u, int v){
	lz(id);
	if(l > v || u > r)return 0;
	if(u <= l && r <= v){
		return T[id].val;
	}
	int mid = (l + r)/2;
	return (get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i<=k; i++){
    	cin >> l[i] >> r[i];
    }
    update(1,1,n,1,1,1);
    for(int i = 1; i<=n; i++){
    	dp[i] = get(1,1,n,i,i);	
    	for(int j = 1; j<=k; j++){
    		update(1,1,n,i+l[j],i+r[j],dp[i]);
    	}
    }
    dp[n] = get(1,1,n,n,n);
    cout << dp[n];
    return 0;
}
