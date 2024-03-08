#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "Block" 
using namespace std;
//**Variable**//
int t;
int n, A[1000005];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    //... cost = max(sum_choose, max(sum[1,b1-1],sum[b1+1,b2-1],...,sum[bm,n]))
    cin>>t;
    while(t--){
    	cin>>n;
    	for(int i = 1; i<=n; i++)cin>>A[i];
    }

    return 0;
}
