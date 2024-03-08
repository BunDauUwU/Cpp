#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Jelly" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t, b, a,n;
ll ans=0;
int tool[100000];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	ans=0;
    	cin>>a>>b>>n;
    	for(int i=1;i<=n;i++){
    		cin>>tool[i];
    		ans+=min(tool[i],a-1);
    	}
    	ans += b;
    	cout<<ans<<"\n";
    }
    return 0;
}
