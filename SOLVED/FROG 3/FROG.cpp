#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "FROG" 
using namespace std;
//**Variable**//
ll n, c;
ll A[2000005];
ll dp[2000005];
//**Struct**//
struct line{
	ll m, b, k;
};
deque<line> hull;
//**Function**//
ll calc(line a, ll x){
	ll m = a.m;
	ll b = a.b;
	return m*x + b;
}
ll r(ll a, ll b){
	return a/b - ((a*b < 0) && (a%b!=0));
}
bool isCut(line& a, line& b){
	if(a.m == b.m)a.k = (a.b > b.b ? inf : -inf);
	else a.k = r(b.b - a.b, a.m - b.m);
	return a.k >= b.k; 
}
bool revisCut(line& b, line& a){
	if(a.m == b.m)a.k = (a.b > b.b ? inf : -inf);
	else a.k = r(b.b - a.b, a.m - b.m);
	return a.k >= b.k; 
}
void add(ll m, ll b){
	line E = {m, b, 0ll};
	while(hull.size() >= 2 && (isCut(E,hull.back()),
							 revisCut(hull[hull.size() - 2], hull.back()),
							 E.k < hull.back().k)){
		hull.pop_back();
	}
	hull.push_back(E);
}
void insert(int i){
	add(-A[i]*2ll, dp[i] + (A[i]*A[i]));
}
ll xuly(ll x){
	while(hull.size() >= 2 && calc(hull[0],x) >= calc(hull[1],x)){
		hull.pop_front();
	}
	return calc(hull[0],x);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
   	cin>>n>>c; 
    for(int i = 0; i<n; i++){
    	cin>>A[i];
    }
    dp[0] = 0; 
    insert(0);
	for(int i = 1; i<n; i++){
		ll x = xuly(A[i]);
		dp[i] = c + (A[i]*A[i]) + x;
		insert(i);
	}    
	cout<<dp[n-1];
    return 0;
}
