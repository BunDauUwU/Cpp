#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "CBARN" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//
struct dp{
	int a, b;
};
//**Variable**//
ll n,sum=0,ans=1e18,pre=0;
ll A[100005],d[100005];
vector<ll> ranch[100005];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    d[0]=0;
    for(int i=1;i<=n;i++){
    	d[i]=i*i;
    }
    for(int i=0;i<n;i++){
    	cin>>A[i];
    }
  	for(int i=0;i<n;i++){
  		if(A[i]==0)continue;
  		for(int j=n-i;j<n;j++){
  			ranch[i].push_back(d[j]);
  		}
  		for(int j=0;j<n-i;j++){
  			ranch[i].push_back(d[j]);
  		}
  		
  	}
  	// for(int i=0;i<n;i++){
  	// 	if(A[i]==0)continue;
  	// 	for(int j=0;j<n;j++){
  	// 		cout<<ranch[i][j]<<" ";
  	// 	}cout<<"\n";
  	// }
  	for(int i=0;i<n;i++){
  		sum = 0;
  		pre = i;
  		if(A[i]==0)continue;
  		for(int j=0;j<n;j++){
  			if(A[j]==0)continue;
  			for(int k=pre;k<pre+A[j];k++){
  				// cout<<ranch[j][k%n]<<" ";
  				sum+=ranch[j][k%n];
  			}
  			pre+=A[j];
  			// cout<<"\n";
  		}



  		// cout<<"____________\n";
  		ans=min(ans,sum);
  	}
  	cout<<ans;
    return 0;
}
