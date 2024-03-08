#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "uwu" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
const ll overf = 1e6 + 7;
ll n, k; 
ll A[400005];
ll dp[400005][31];
ll idx[400005 + overf];
ll MX[400005];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    memset(MX, -inf, sizeof(MX));
    cin >> n >> k;
    for(ll i = 1; i<=n; i++){
        cin >> A[i];
        ll pre = idx[i - A[i] + overf];

        if(pre)for(ll j = 0; j<=k; j++)dp[i][j] = dp[pre][j] + A[i];

        dp[i][0] = max(dp[i][0], A[i]);

        for(ll j = 0; j<=k; j++){
            dp[i][j] = max(dp[i][j], MX[j-1] + A[i]);
        }

        for(ll j =  0; j<=k; j++){
            MX[j] = max(MX[j], dp[i][j]);
        }
        idx[i - A[i] + overf] = i;
    }
    ll ans = -1e9;
    for(ll i = 1; i<=n; i++){
        for(ll j = 0; j<=k; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
