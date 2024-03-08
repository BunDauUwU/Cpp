#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "array" 
using namespace std;
//**Variable**//
ll t;
ll n, q;
ll x, b;
ll dp[200005];
ll last[200005];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n>>q;
    	for(int i = 1; i<=n; i++){
    		cin>>b>>x;
    		if(b == 1){
    			last[i] = x;
    			dp[i] = dp[i-1] + 1ll;
    		}else{
    			last[i] = last[i-1];
    			if(x + 1 > 4e18 / dp[i-1]){
    				dp[i] = 4e18;
    				continue; 
    			}
    			dp[i] = dp[i-1]*(x+1ll);
    		}
    	}
    	while(q--){
    		ll k;
    		cin >> k;
    		while(true){
    			ll idx = lower_bound(dp + 1, dp + 1 + n, k) - dp;
    			if(dp[idx] == k){
    				cout<<last[idx]<<" "; break;
    			}
    			if(k % dp[idx - 1] == 0){
    				cout<<last[idx-1]<<" "; break;
    			}
    			k = k % dp[idx-1];
    		}
    	}
    	cout<<"\n";
    }
    
    return 0;
}
