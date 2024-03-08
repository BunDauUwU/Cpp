#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "WHOME" 
using namespace std;
//**Variable**//
ll n, m, c, p;
ll A[200006];
ll s[200006];
ll dp[200005][((1<<6)+1)];
ll l[200005][((1<<6)+1)];
ll len[(1<<6)+1];
//**Struct**//

//**Function**//
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>m>>p>>c;
    for(ll i = 1; i<=n; i++){
        cin>>A[i];
    }
    for(ll i = 1; i<=m; i++){
        cin>>s[i];
    }
    sort(A+1,A+1+n);
    sort(s+1,s+1+m);
    for(ll i = 0; i<=n; i++){
        for(ll mask = 0; mask<=(1<<m)-1; mask++){
            dp[i][mask] = -1e18;
        }
    
    for(ll mask = 1; mask<=(1<<m)-1;mask++)
        l[0][mask] = 1e18;
    }
    for(ll ht = 0; ht < (1<<m); ht++){
        for(ll j = 0; j<m;j++){
            if((ht >> j)&1)len[ht]+=(s[j+1]);
        }
    }
    for(ll i = 2; i<=n; i++){
        for(ll mask = 0; mask<=(1<<m)-1; mask++){
            if(dp[i][mask] < dp[i-1][mask]){
                dp[i][mask] = dp[i-1][mask];
            }
            for(ll j = 1; j<=m; j++){
                if(len[mask] + s[j] > i)continue;
                ll add = p - (A[i] - A[i-s[j]+1])*(A[i] - A[i-s[j]+1])*c;
                ll tmp = mask | (1<<(j-1));
                if(dp[i-s[j]][mask] == -1e18){
                    dp[i][tmp] = add;

                }
                if(dp[i][tmp] < dp[i-s[j]][mask] + add){
                    dp[i][tmp] = dp[i-s[j]][mask] + add;

                }
            }
        }
    }
    cout<< dp[n][(1<<m)-1];
    return 0;
}
