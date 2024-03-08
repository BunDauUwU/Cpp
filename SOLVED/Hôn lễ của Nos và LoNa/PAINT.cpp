#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
#define FILE "PAINT" 
using namespace std;
//**Variable**//
int w, b, r, K, m;
int dp[310][310][610][2];
int ch[610][610];
int gr[610][610];
int gb[610][610];
int f[610];
int mod = 1e9+7;
//**Struct**//

//**Function**//
void Add(int &u, int v){
	u%=mod;
	v%=mod;
	u += v;
	if(u>=mod) u-=mod; 
}
int xuly(int K, int n){
	if(ch[K][n] != -1)return ch[K][n];
	if(K==1)return n;
	if(K==0)return 1;
	if(K>n)return 0;
	ch[K][n] = xuly(K,n-1);
	Add(ch[K][n], xuly(K-1,n-1));
	return ch[K][n];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>w>>b>>r>>K>>m;
    memset(ch,-1,sizeof(ch));
    dp[1][0][0][0] = 1;
    dp[0][1][0][1] = 1;
    for(int i = 0; i<=r; i++){
    	for(int j = 0; j<=b; j++){
    		for(int k = 0; k<=b+r; k++){
    			for(int t = 0; t<=1; t++){
    				if(dp[i][j][k][t]){
    					if(i == r && j == b){
    						Add(f[k],dp[i][j][k][t]);
    						continue;
    					}
    					if(t==0){
    						Add(dp[i+1][j][k][t], dp[i][j][k][t]);
    						Add(dp[i][j+1][k+1][1],dp[i][j][k][t]);
    						continue;
    					}
    					if(t==1){
    						Add(dp[i+1][j][k+1][0], dp[i][j][k][t]);
    						Add(dp[i][j+1][k][t],dp[i][j][k][t]);
    						continue;
    					}
    				}
       			}
    		}
    	}
    }
    gr[0][0] = 1;
    gb[0][0] = 1;
    int ans = 0;
    for(int i = 1; i<=w; i++){
    	for(int j = 1; j<=w; j++){
    		for(int k = 0; k<i; k++){
    			if(i - k < K) Add(gb[i][j], gb[k][j-1]);
    		}
    	}					
   	}
   	for(int i = 0; i<=w; i++){
   		for(int j = 0; j<=r+b+1; j++){
   			if(i+j > 0){
   				for(int k = 0; k<=i; k++){
   					if(i-k < K) Add(gr[i][j],gr[k][j-1]);
   				}
   			}
   		}
   	}
   	for(int i = m; i<=r+b; i++){
   		int u = i - m;
   		int v = r + b + 1 - i;
   		for(int j = 0; j<=w; j++){
   			int res = (1ll*xuly(u,i)*gb[j][u])%mod;
   			res = (1ll*res*gr[w-j][v])%mod;
   			res = (1ll*res*f[i])%mod;
   			Add(ans,res);
   		}
   	}
   	cout<<ans;
    return 0;
}
