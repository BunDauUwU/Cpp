#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "uwu" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
const ll mod = 1e9 + 7;
ll n, q;
ll mblock = 0;
ll A[400005];
ll l, r, x ,y, k;
ll res[400005];
ll T[8*400005];
ll idx[8*400005];
//**Struct**//
struct input{
    ll type;
    ll l, r, val, k;
    ll id;
};
vector<input> query;
//**Function**//
ll calc(ll n, ll k){
    if(k == 0)return 1;
    if(k == 1)return n;
    return ((calc(n,k/2)*calc(n,k/2))%mod*calc(n,k%2))%mod;
}
bool cmpQ(input a, input b){
    if(a.val == b.val) return a.type < b.type;
    return a.val < b.val;
}

void build(ll id,ll l, ll r){
    if(l == r)return idx[l] = id, T[id] = 1, void();
    ll mid = ( l + r ) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    T[id] = T[id*2]*T[id*2+1]%mod;
}
void update(ll pos, ll val){
    ll id = idx[pos];
    T[id] = val; 
    while(id/=2){
        T[id] = (T[id*2]*T[id*2+1])%mod;
    }
}
ll get(ll id, ll l, ll r, ll u, ll v){
    if( l > v || u > r )return 1;
    if( u <= l && r <= v )return T[id];
    ll mid = (l + r)/2;
    return (get(id*2,l,mid,u,v)*get(id*2+1,mid+1,r,u,v)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> q;
    build(1,1,n);
    for(ll i = 1; i<=n; i++){
        cin >> A[i];
        query.push_back({0,i,i,A[i],1,0});
    }
    for(ll i = 1; i<=q; i++){
        cin >> l >> r >> x >> y >> k;
        query.push_back({1,l,r,x - 1,k,i});
        query.push_back({2,l,r,y,k,i});
    }   
    sort(query.begin(), query.end(), cmpQ);
    for(ll i = 0; i < query.size(); i++){
        ll t = query[i].type; 
        ll l = query[i].l;
        ll r = query[i].r;
        ll val = query[i].val;
        ll k = query[i].k;
        ll id = query[i].id;
        if( t == 0 ){
            update(l, val);
        }
        if( t == 1 ){
            res[id] = calc(calc(get(1,1,n,l,r),k), mod - 2)%mod;
        }
        if( t == 2 ){
            res[id] = (calc(get(1,1,n,l,r),k) * res[id])%mod;
        }
    }
    for(ll i = 1; i<=q; i++){
        cout<< (res[i]) <<"\n";
    }
    return 0;
}
