#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "sum" 
using namespace std;
//**Variable**//
ll n, q;
ll s, d, k;
ll ans;
ll A[200005];
ll pre[320][200005];
ll range[320][200005];
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        ll sz = sqrt(n);
        for(ll i = 0; i<n; i++){
            cin>>A[i];
        }
        while(sz*sz < n)sz++;
        for(ll i = 0; i<sz; i++){
            for(ll j = 0; j<=i; j++){
                range[i][j] = 0ll;
                pre[i][j] = 0ll;

            }
            for(ll j = 0; j<n; j++){
                range[i][j+i+1] = range[i][j] + A[j] * ( j / ( i + 1ll) + 1ll);
                pre[i][j+i+1] = pre[i][j] + A[j];
            }
        }
        while(q--){
            cin>> s >> d >> k;
            ans = 0;
            s--;
            if(d > sz){
                for(ll i = s; i<=s+d*(k-1); i+=d){
                    ans = ans + A[i]*((i-s)/d+1ll);
                }
                cout<<ans<<" ";
                continue;
            }
            ll r = s + d*k - d;
            ll l = s;
            cout<<range[d-1][r + d] - range[d-1][l] - (pre[d-1][r + d] - pre[d-1][l])*(l/d)<<" ";
            continue;
        }
        cout<<"\n";

    }
    return 0;
}
