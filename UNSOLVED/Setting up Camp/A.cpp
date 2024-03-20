#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "A" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int t;
int n;
int A[300005];
int l[300005];
int r[300005];
string s;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> t;
    while(t--){
    	cin >> n;
    	ld m = n;
    	cin >> s;
    	s = ' ' + s;
    	int cur;
    	int op;
    	int curl = 0;
    	int curr = 0;
    	int opl = 0;
    	int opr = 0;
    	int ans = -1;
    	ld eq = n;
    	for(int i = 1; i<=n; i++){
    		if(s[i] == '0'){
    			opl++;
    		}else{
    			opr++;
    		}
    	}    	
    	for(int i = 0; i<=n; i++){
    		if(s[i] == '0'){
    			curl++;
    			opl--;
    		}
    		if(s[i] == '1'){
    			curr++;
    			opr--;
    		}
    		cur = curl + curr;
    		op = opl + opr;
    		if( curl >= curr  && opr >= opl){
    			ll x = i;
    			ld suf = abs(m/2.0 - x);
    			if(suf < eq){
    				eq = suf;
    				ans = i;
    			}
    		}
    	}
    	cout << ans << "\n";
    }
    
    return 0;
}
