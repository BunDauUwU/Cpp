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
ll n;
ll x[5];
ll y[5];
//**Struct**//

//**Function**//
ll calc(ll minX, ll minY, ll maxY){
	while((minX + minY) % 2 != 0) ++minY;
	while((minX + maxY) % 2 !=0 ) --maxY;
	if(minY > maxY)return 0;
	return (maxY - minY + 2)/2;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin >> n;
	ll minX =-1e18, minY = -1e18;
	ll maxX = 1e18, maxY = 1e18;
	for(int i = 0; i<n; i++){
		for(int i = 0; i<4; i++){
			cin>>x[i]>>y[i];
		}
		ll lowX = 1e18, lowY = 1e18;
		ll highX = -1e18, highY = -1e18;
		for(int j = 3,i = 0; i<4; j = i++){
			if((x[i] < x[j]) == (y[i] < y[j])){
				lowX = min(lowX,x[i] - y[i]);
				highX = max(highX, x[i] - y[i]);
			}else{
				lowY = min(lowY, x[i] + y[i]);
				highY = max(highY, x[i] + y[i]);
			}

		}
		minX = max(minX, lowX);
		maxX = min(maxX, highX);
		minY = max(minY, lowY);
		maxY = min(maxY, highY);
	}
	minX++; minY++; 
	maxX--; maxY--;
	if(minX > maxX || minY > maxY){
		cout<<0;
	}else{
		cout << calc(minX, minY, maxY) * ((maxX - minX + 2) / 2) + calc(minX + 1, minY, maxY) * ((maxX - minX + 1) / 2);
	}
    return 0;
}
