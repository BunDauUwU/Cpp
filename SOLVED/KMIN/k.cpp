#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "uwu" 
using namespace std;
//**Variable**//
ll A[5000001];
ll B[5000001];
ll n, m, k;
ll cnt[5000001];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin >> n >> m >> k;
    for(ll i = 1; i<=n; i++){
        cin >> A[i];
    }
    for(ll i = 1; i<=m; i++){
        cin >> B[i];
    }
    sort(A+1,A+1+n);
    sort(B+1,B+1+m);
    for(ll i = 1; i<=m; i++){
        q.push({A[1]+B[i],i});
        cnt[i] = 2;
    }
    for(ll i = 1; i<=k; i++){
        auto t = q.top();q.pop();
        cout<<t.fi<<"\n";
        if(cnt[t.se] < n){
            q.push({A[cnt[t.se]++] + B[t.se],t.se});
        }
    }
    return 0;
}

