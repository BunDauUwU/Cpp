#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "NATDIV" 
using namespace std;
//**Variable**//
ll n;
ll s = 0;
ll diff = 0;
ll x, y;
ll countup[1000006];
ll sz[1000006];
ll isnotPrime[10000006];
//**Struct**//

//**Function**//
void sang(){
	memset(sz,0,sizeof(sz));
	memset(countup,0,sizeof(countup));
	for(int i = 1; i<=1000003; i++){
     	sz[i]++;
    	countup[i] ++;
    }

	for(ll i = 2; i<=1000003; i++){
		// if(i*i > 1000003)continue;
		for(ll j = i; j<=1000003; j+=i){
			countup[j]+=i;
			sz[j]++;
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    sang();
    for(int i = 1; i<=1000003; i++){
    	sz[i] += sz[i-1];
    	countup[i] += countup[i-1];
    }
    while(n--){
    	cin>>x>>y;
    	s = countup[y] - countup[x-1];
    	diff = sz[y] - sz[x-1];
    	cout<<diff<<" "<<s;
    	cout<<"\n";
    }
    
    return 0;
}
