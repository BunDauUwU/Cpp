#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "dem" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
ll n, a, b;
ll factor[4 * 1000006];
ll mul[4 *1000006];
ll isNotPrime[4*1000006];
vector<int> v;
//**Struct**//

//**Function**//

void sang(){
	isNotPrime[1] = isNotPrime[0] = 1;
	int cnt  = 0;
	for(ll i = 1; i<=1000006; i++){
		if(!isNotPrime[i]){
			cnt++;
			for(ll j = i*2; j<=1000006; j+=i){
				mul[j]= min(mul[j]*i,n+1);
				isNotPrime[j] = 1;
			}
		}
	}
	cout<<cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin >> n >> a >> b;
    if(n <= 4*1000006){
    	sang();

    }
    
    return 0;
}
