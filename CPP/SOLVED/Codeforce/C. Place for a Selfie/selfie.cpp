#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "selfie" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t;
ll idx;
ll n,m;
ll a,b,c;
ll k[100005];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	for(int i=1;i<=n;i++){
    		cin>>k[i];
    	}
    	sort(k+1,k+1+n);
    	// cout<<lower_bound(k+1,k+1+n,5)-k<<"\n";
    	for(int i=1;i<=m;i++){
    		cin>>a>>b>>c;
    		idx = lower_bound(k+1,k+1+n,b)-k;
    		// cout<<k[idx]<<"|";
    		if(idx<=n && (b-k[idx])*(b-k[idx]) - 4*a*c <0){
    			cout<<"YES\n";
    			cout<<k[idx]<<"\n";
    			continue;
    		}
    		if(idx>1 && (b-k[idx-1])*(b-k[idx-1])-4*a*c<0){
    			cout<<"YES\n";
    			cout<<k[idx-1]<<"\n";
    			continue;
    		}
    		cout<<"NO\n";
    	}
    	cout<<"\n";
    }
    
  return 0;
}