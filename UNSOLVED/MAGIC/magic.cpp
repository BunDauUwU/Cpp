#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "magic" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
ll n, m , q;
ll l[200005];
ll r[200005];
ll x,  y;
ll cur = 1;
//**Struct**//
struct Q_Q{
	ll pos;
	ll power;
	ll type;
}query[4*200005];
//**Function**//
bool cmp(Q_Q a, Q_Q b){
	if(a.pos == b.pos){
		return a.type < b.type;
	}
	return a.pos < b.pos;
}
bool cmp2(Q_Q a, ll b){
	return a.pos < b;
}
void SUB2(){
	ll ans;
	for(ll i = 1; i<=q; i++){
		ans = 0;
		x = lower_bound(query + 1, query + 1 + cur, l[i], cmp2) - query;
		y = lower_bound(query + 1, query + 1 + cur, r[i], cmp2) - query;
		map<ll,ll> m;
		ll s = 0;
		ll len = 0;
		for(ll j = x; j<=y; j++){
			if(query[j].type == 1)continue;
			s += query[j].power;
			len ++;
			if((m[s] && len > 1) || s == 0){
				ans++;
				m.clear();
				s = 0;
			}
			m[s] = 1;
		}	
		cout << ans << "\n";
	}
}
void SUB3(){
	map<int,int> m;
	int s = 0;
	int len = 0;
	int ans = 0;
	for(int i = 1; i<=cur; i++){
		if(query[i].type == 1)continue;
		s+= query[i].power;
		len++;
		if((m[s] && len > 1) || s == 0){
				ans++;
				m.clear();
				s = 0;
			}
		m[s] = 1;
	}
	cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> m >> q;
    for(ll i = 1; i<=n; i++){
    	cin >> x >> y;
    	query[cur++] = {x,-y,0};
    }
    for(ll i = 1; i<=m; i++){
    	cin >> x >> y;
    	query[cur++] = {x,y,0};
    }
    ll u = 1e9, v = 0;
    for(ll i = 1; i<=q; i++){
    	cin >> x >> y;
    	l[i] = x;
    	r[i] = y;
    	u = min(u,x);
    	v = max(v,y);
    	query[cur++] = {x,0,1};
    	query[cur++] = {y,0,1};
    }
    cur--;
    sort(query + 1, query + 1 + cur, cmp);
    if(n <= 10 && m <= 10 && q == 1 && u == 1 && v == 1e9){
    	ll s = 0;
    	map<ll,ll> m;
    	ll ans = 0;
    	ll len = 0;
    	for(ll i = 1; i<=cur; i++){
    		if(query[i].type == 1)continue;
    		s += query[i].power;
    		len ++;
    		if((m[s] && len > 1) || s == 0){
    			ans++;
    			s = 0;
    			len = 0;
    			m.clear();
    		}
    		m[s] = 1;
    	}	
    	cout << ans;
    }
    else if(n <= 3000 && m <= 3000 && q<= 3000)SUB2();
    else{
    	SUB3();
    }
    return 0;
}