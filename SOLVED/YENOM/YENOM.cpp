#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "YENOM" 
using namespace std;
//**Variable**//
ll n, T;
ll ans = 1;
// ll cant =  0;
ll A[2001];
// ll dp[2001][2001];
// ll ans = 0;
// map<ll, ll> m;
ll d[20001];
ll mark[20001];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> T;
    //(bỏ qhd --> đồ thị?)
    // liên thông có hướng x-->y
    // đi qua?
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    sort(A,A+n);
    n = A[n-1];
    for(int i = 0; i<=n; i++) d[i] = T+1;
    d[0] = 0;
    for (int i = 1; i < n; i++){
        ll x = -1;
        for (int j = 0; j < n; j++) 
        if (!mark[j]){
            if (x == -1 || d[j] < d[x]) {
                x = j;
            }
        }
        if (d[x] > T) break;
        mark[x] = 1;
        for (auto i : A){ 
            int y = (x + i) % n;
            d[y] = min(d[y], d[x] + i);
        }
    }
    ans = 0;
    for(int i = 0; i < n; i++){ 
        if (d[i] <= T){
            ans = ans + ((T - d[i]) / n) + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
