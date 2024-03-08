#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "d" 
using namespace std;
//**Variable**//
int n;
int A[1000006];
int q;
int T[4*1000006];
int idx[4*1000006];
int last[4*1000006];
int res[4*1000006];
//**Struct**//
struct inp{
	int i;
	int j;
	int s;
    int id;
};
inp query[4000006];
//**Function**//
bool cmp(inp a, inp b){
	if(a.j == b.j){return a.s < b.s;}
	return a.j < b.j;
}
void build(int id, int l, int r){
	if(l == r) return idx[l] = id, T[id] = 0, void();
	int mid = (l+r)/2;
	build(id*2,l, mid);
	build(id*2+1,mid+1,r);
}
void update(int pos, int val){
	int id = idx[pos];
	T[id] = T[id] + val;
	// id/=2;
	while(id/=2){
		T[id] = T[id*2] + T[id*2+1];
		// id/=2;
	}
}
int get(int id, int l, int r, int u, int v){
	if(l > r || u > v || l > v || u > r)return 0;
    // if(l != r && l < r){
    //     T[id] = T[id*2] + T[id*2+1];
    // }
	if(u<=l && r<=v)return T[id];
	int mid = (l + r)/2;
	return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    memset(last,0,sizeof(last));
    cin>>n;
    for(int i = 1; i<=n; i++){
    	cin>>A[i];
    	query[i].i = A[i];
    	query[i].j = i;
    	query[i].s = 0;
    }
    cin>>q;
    for(int i = n+1; i<=n+q; i++){
    	cin>>query[i].i>>query[i].j;
        query[i].id = i - n;
     	query[i].s = 1;
    }
    sort(query+1,query+n+q+1,cmp);
    build(1,1,n);
    for(int i = 1; i<=n+q; i++){
    	if(query[i].s == 0){
    		int num = query[i].i; 
    		int pos = query[i].j;
    		update(pos,1);
    		if(last[num]>0){
    			update(last[num],-1);
    		}
    		last[num] = pos;
    	}else{	
    		int l = query[i].i;
    		int r = query[i].j;
    		res[query[i].id] = get(1,1,n,l,r);
    	}
    }
    for(int i = 1; i<=q; i++){
        cout<<res[i]<<"\n";
    }
    return 0;
}
