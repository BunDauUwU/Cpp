#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Door" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,x,y;
int A[1000006];
int cnt = 0;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>n>>x>>y;
    if(x>y){
    	cout<<n;
    	return 0;
    }
    for(int i=1;i<=n;i++){
    	cin>>A[i];
    	if(A[i]-x<=0){
    		cnt++;
    	}
    }
    if(cnt%2==0){cout<<cnt/2;}
    else{
    	cout<<cnt/2+1;
    }
    return 0;
}
