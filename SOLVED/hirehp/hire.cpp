#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "hire" 
using namespace std;
//**Variable**//
ll n;
ll t[500505];
ll p[500505];
ll ans[500505];
ll idx[500505];
ll T[8*500505];
//**Struct**//

//**Function**//
void build(ll id, ll l, ll r){
	if(l == r)return T[id] = 1e18,idx[l] = id,void();
	ll mid = (l + r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
void update(ll id, ll l, ll r, ll u, long long val) {
    if (u < l || r < u) return ;
    if (l == r) {
        T[id] = val;
        return ;
    }
    ll mid = (l + r) / 2;
    update(id*2,   l,     mid, u, val);
    update(id*2+1, mid+1, r,   u, val);

    T[id] = min(T[id*2], T[id*2+1]);
}
ll get(ll id, ll l, ll r, ll u, ll v){
	if( l > r || u > v || u > r || l > v)return 1e18;
	if( u <= l && r <= v ) return T[id];
	ll mid = (l + r)/2;
	return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v)); 
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    memset(T,0,sizeof(T));
    cin>>n;
    for(ll i = 1; i<=n; i++){
    	cin>>t[i]>>p[i];
    }
    build(1,1,n+1);
    T[idx[n+1]] = 0;
    ans[n] = p[n];
    update(1,1,n+1,n,ans[n]);
    for(ll i = n-1; i>=1; i--){
   		ans[i] = get(1,1,n+1,i+1,t[i]+1) + p[i];
    	update(1,1,n+1,i,ans[i]);
    }
    cout<<ans[1];
    return 0;
}
