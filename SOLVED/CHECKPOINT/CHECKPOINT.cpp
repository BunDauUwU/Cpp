#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "CHECKPOINT" 
using namespace std;
//**Variable**//
ll n, k;
ll A[100006];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin >> n >> k;
	ll ans = -1e18;
	ll s = 0;
	ll cnt = 0;
	for(int i = 1; i<=n; i++){
		cin>>A[i];
	}
	for(int i = 1; i<=n; i++){
		s = A[i];
		cnt = A[i] < 0;
		for(int j = i + 1; j<=n; j++){
			s += A[j];
			ans = max(ans,s);
			if(A[j] < 0)cnt++;
			if(cnt > k)break;
		}
	}
	cout<<ans;
    return 0;
}
