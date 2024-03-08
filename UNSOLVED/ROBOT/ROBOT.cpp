#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "ROBOT" 
using namespace std;
//**Variable**//
ll n, m;
ll ans = 0; 
ll mod = 1e9 + 7;
//**Struct**//

//**Function**//
ll C(ll n, ll k){
	ll N = 1, K = 1, NK = 1;
	for(ll i = 2; i<=n; i++){
		N = (i*N)%mod;
		if(i<=N-K){
			NK=(NK*i)%mod;
		}
	}
	for(ll i = 2; i<=k; i++){
		K=(K*i)%mod;
	}
	ll res = (N / ((K*NK)%mod))%mod;
	cout<<res<<"\n";
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>m;
    // n++;m++;
    if(n > m)swap(n,m);
    for(ll k = 0; k<=n; k++){
    	ans = (ans+(C(n+m-k,k)%mod)*(C(n-k+m-k,n-k)%mod))%mod;
    }
    cout<<ans;
    return 0;
}
