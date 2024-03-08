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
string s;
int q;
int t, i , j;
char c;
int idx[100005];
//**Struct**//
struct ngoac{
	int o, c;
	ngoac friend operator+(ngoac left, ngoac right){
		ngoac mid;
		int done = min(left.o, right.c);
		mid.o = left.o  + right.o - done;
		mid.c = left.c + right.c - done;
		return mid;
	} 
}T[4*100005];
//**Function**//
void build(int id, int l, int r){
	if(l == r){
		idx[l] = id;
		if(s[l] == '('){
			T[id] = {1,0};
		}else{
			T[id] = {0,1};
		}
		return void();
	}
	int mid = (l + r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	T[id] = T[id*2] + T[id*2+1];
}
void update(int pos, char c){
	int id = idx[pos];
	if(c == '('){
			T[id] = {1,0};
		}else{
			T[id] = {0,1};
		}
	while(id/=2){
		T[id] = T[id*2] + T[id*2+1];
	}
}
ngoac get(int id, int l, int r, int u, int v){
	if( l > r || u > v || u > r || l > v )return {0,0};
	if( u <= l && r <= v )return T[id];
	int mid = (l + r)/2;
	return get(id*2, l, mid, u, v) + get(id*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>q;
    cin>>s;
    s = " " + s;
    build(1,1,n);
    while(q--){
    	cin>>t;
    	if(!t){
    		cin>>i>>c;
    		update(i,c);
    	}else{
    		cin>>i>>j;
    		auto ans = get(1,1,n,i,j);
    		cout<<(ans.o == 0 && ans.c == 0);
    	}
    }
    
    return 0;
}
