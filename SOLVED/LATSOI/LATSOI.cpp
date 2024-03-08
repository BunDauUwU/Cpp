#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "LATSOI" 
using namespace std;
//**Variable**//
int n,q;
int t, l, r;
int T[4*100005 + 5];
int lz[4*100005 + 5];
int sz[4*100005 + 5];
//**Struct**//

//**Function**//
void build(int id, int l, int r){
	if( l == r )return T[id] = 0, sz[id] = 1, void();
	int mid = (l + r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	sz[id] = sz[id*2] + sz[id*2+1];
}
void down(int id){
	if(lz[id]){
		// T[id] = sz[id] - T[id];
		T[id*2] = sz[id*2] - T[id*2];
		T[id*2+1] = sz[id*2+1] - T[id*2+1];
		lz[id*2]^=1;
		lz[id*2+1]^=1;
		lz[id] ^= 1;
	}
	return ;
}
void update(int id, int l, int r, int u, int v){
	if( r < u || v < l || r < l)return ;
	if(u <= l && r<=v){
		T[id] = sz[id] - T[id];
		lz[id] ^= 1;
		// down(id);
		return ;
	}
	int mid = (l + r)/2;
	down(id);
	update(id*2, l, mid, u , v);
	update(id*2+1, mid+1, r, u, v);
	T[id] = T[id*2] + T[id*2+1];
}
int get(int id, int l, int r, int u, int v){
	if( r < u || v < l || r < l)return 0;
	if(u <= l && r<=v){
		// cout<<l<<" "<<r<<"\n";
		return T[id];
	}
	int mid = (l + r)/2;
	down(id);
	return get(id*2, l, mid, u , v)+get(id*2+1, mid+1, r, u, v);

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>q;
    build(1,1,n);
    while(q--){
    	cin>>t>>l>>r;
    	l++; r++;                                                                                                                                                                
    	if( t == 0 ){
    		update(1,1,n,l,r);
    	}else{
    		cout<<get(1,1,n,l,r)<<'\n';
    	}
    }
    
    return 0;
}
