#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "emote" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
ll t, n, m, k;
ll A[1000006],ans=0;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
    	cin>>A[i];
    }
    sort(A+1,A+1+n,greater<int>());
    if(k>=m){
    	cout<<A[1]*m;
    }else{
    	while(m>=k+1){
    		m= m - (k+1);
    		ans+=A[1]*k+A[2];
    	}
    	if(m){
    		ans+=A[1]*m;
    	}
    	cout<<ans;
    }
    
    return 0;
}
