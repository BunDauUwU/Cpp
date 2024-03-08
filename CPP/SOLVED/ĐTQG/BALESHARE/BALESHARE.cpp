#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "BALESHARE" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int S[100005];
int ans;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>S[i];
		ans+=S[i];
	}   
	sort(S+1,S+1+n);
    for(int i=1;i<=n;i++){
    	
    }
    return 0;
}
