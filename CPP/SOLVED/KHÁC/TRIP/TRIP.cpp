#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "TRIP" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int c[1001][1001];
int F[100005][101];
//**Function**//
int dp( ll k , ll mask ){
	// cout<<mask<<"\n";
	if(mask == 0 )return 0;
	int res = F[mask][k];
	if(res == 0 ){
		res = inf;
		for(int i=0;i<n;i++){
			if(mask &(1<<i)) res = min(res, dp(i,mask & ~(1<<i)) +c[i][k]);
		}
	}
	F[mask][k]= res;
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	int ans = inf;
	for(int i=0;i<n;i++){
		ans = min(ans, dp(i,(1<<n)-1));
	}
    cout<<ans;
    return 0;
}
