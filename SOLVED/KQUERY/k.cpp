#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "k" 
using namespace std;
//**Variable**//
int n;
int A[1000006];
int q,x,y,k;
int T[4*1000006];
int idx[4*1000006];
int last[4*1000006];
int res[4*1000006];
//**Struct**//
struct inp{
	int i, j;
	int k;
	int id;
	int type;
};
inp query[4*1000006];
//**Function**//
bool cmp(inp a, inp b){
	if(a.k == b.k){return a.type > b.type;}
	return a.k > b.k;
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
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    memset(last,0,sizeof(last));
    cin>>n;
    build(1,1,n);
   	for(int i = 1; i<=n; i++){
   		cin>>A[i];
   		query[i].k = A[i];
   		query[i].i = i;
   		query[i].j = i;
   		query[i].type = 0;
   	}
   	cin>>q;
   	for(int i = n+1; i<=n+q; i++){
   		cin>>query[i].i>>query[i].j>>query[i].k;
   		query[i].id = i - n;
   		query[i].type = 1;
   	}
   	sort(query+1,query+1+n+q, cmp);
   	for(int i = 1; i<=n+q; i++){
   		// cout<<query[i].k<<"\n";
   		if(query[i].type == 0){
   			update(query[i].i,1);
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
