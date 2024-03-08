#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "VUMON" 
using namespace std;
//**Variable**//
ll n;
ll x;
bool isNotPrime[4*1000006];
ll pre[4*1000006];
ll mark[4*1000006];
vector<ll> prime;
//**Struct**//

//**Function**//
void precalc(){
    for(ll i = 1; i<=4*1000000; i++){
        pre[i] = i-1;
    }
    for(ll i = 2; i<=4*1000000; i++){
        // if(!isNotPrime[i]){
            // if(i*i > 4*1000006)continue;
            for(ll j = i*2; j<=4*1000000; j+=i){
                isNotPrime[j] = 1;
                pre[j] -= pre[i];
            }
        // }
    }
}
ll solve(ll x){
    ll ans = 0;
    vector<ll> v(0);
    for(ll i = 1; i*i<=x; i++){
        if( x % i == 0){
            v.push_back(i);
            if( x / i != i)v.push_back(x/i);
        }
    }
    sort(v.begin(), v.end());
    for(auto it : v){
        ll sum = x / it  - 1;
        ll res = pre[sum];
        ans += res;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    precalc();
    cin >> n;
    for(ll i = 1; i<=n; i++){
        cin >> x;
        cout<< solve(x) <<" "; 
    }
    return 0;
}
