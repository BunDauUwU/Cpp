#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "road" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
ll n, k;
ll l[51], r[51];
const ll maxN = 5 * 100005;
ll bit[maxN];
ll mod = 1e9 + 7;
ll dp[maxN];
//**Struct**//

//**Function**//
void update(int x, int val){
    for(int i = x; i<=maxN; i += i & (-i)){
        bit[i] = (bit[i] + val)%mod;
    }
}
ll get(int x){
    if(x <= 0)return 0;
    ll ans = 0;
    for(int i = x; i>0; i -= i & (-i)){
        ans = (ans + bit[i])%mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i<=k; i++){
        cin >> l[i] >> r[i];
    }
    dp[1] = 1;
    update(1,1);
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i] = (dp[i] + get(i - l[j]) - get(i - r[j] - 1))%mod;
        }
        update(i, dp[i]);
    }
    cout << dp[n];
    return 0;
}
