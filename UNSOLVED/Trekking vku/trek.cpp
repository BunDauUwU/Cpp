#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "trek" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
ll n, q;
ll A[500005];
ll B[500005];
ll cost[500005];
ll stamina[500005];
ll res[500005];
ll req[500005];
vector<ll> step;
vector<ll> gift;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n >> q;
    for(int i = 1; i<=n; i++){
    	cin >> A[i];
    }
    for(int i = 1; i<=n; i++){
    	cin >> B[i];
    }
    cost[0] = 0;
    for(int i = 1; i<=n; i++){
		cost[i] = cost[i-1] + A[i];
	}
	cost[n + 1] = cost[n];
	ll cur = 0;
    for(int i = 1; i<=n; i++){
    	req[i] = A[i] + cur;
    	cur += B[i];
    }
    step.push_back(0);
    gift.push_back(0);
    cur = 0;
 	for(int i = 1; i<=n; i++){
 		if(req[i] > step.back()){
 			step.push_back(req[i]);
 			gift.push_back(cur + A[i]);
 		}
 		if(cur){
 			gift.back() = cur;
 		}
 		cur += A[i];
 	}
 	if(cur){
 		gift.back() = cur;
 	}
 	for(int i = 1; i<=q; i++){
 		cin >> stamina[i];
 		int idx = lower_bound(step.begin(),step.end(), stamina[i]) - step.begin();
 		while(step[idx] > stamina[i]) idx--;
 		res[i] = gift[idx];
 	}
    for(int i = 1; i<=q; i++){
    	cout << res[i] << "\n";
    }
    return 0;
}