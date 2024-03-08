#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "balance" 
using namespace std;
//**Variable**//
int t, x, n;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	vector<int> divisor(0);
    	cin>>x>>n;
    	for(int i = 1; i*i <= x; i++){
    		if(x%i == 0){
    			divisor.push_back(i);
    			if( x / i != i )divisor.push_back(x/i);
    		}
    	}
    	int ans = 0;
    	sort(divisor.begin(), divisor.end());
    	for(auto it : divisor){
    		if( it > x/n)break;
    		ans = max(ans, __gcd(x,it));
    	}
    	cout<<ans<<"\n";
    }
    
    return 0;
}
