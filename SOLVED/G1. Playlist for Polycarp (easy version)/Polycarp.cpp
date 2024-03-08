#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "Polycarp" 
using namespace std;
//**Variable**//
ll n, t;
ll l[1000006], g[1000006];
ll dp[(1<<15)+5][4];
ll mod = 1e9 + 7;
//**Struct**//

//**Function**//
ll solve(int mask, int len, int genre){
    if(len == 0)return 1;
    if(len<0)return 0;
    if(len>0 && mask == (1<<n)-1)return 0;
    ll res = dp[mask][genre];
    if(res != -1)return res;
    res = 0;
    for(int i = 0; i<n; i++){
        if((mask>>i)&1 || genre == g[i])continue;
        res = (res + solve(mask |(1<<i), len-l[i],g[i]))%mod;
    }
    return dp[mask][genre] = res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    memset(dp,-1,sizeof(dp));
    cin>>n>>t;
    for(int i = 0; i<n; i++){
        cin>>l[i]>>g[i];
    }
    cout<<solve(0,t,0);
    return 0;
}
