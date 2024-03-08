#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "BaiToan1" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int A[1001],lis[1001],l[1001];
//**Function**//
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>A[i];
    }
    memset(lis,inf,sizeof(lis));
    for(int i=0;i<n;i++){
    	l[i]=lower_bound(lis,lis+n,A[i])-lis;
    	// cout<<A[i]<<" "<<l[i]<<"\n";
    	lis[l[i]++] = A[i];
    	// for(int i=0;i<n;i++){
    		// cout<<lis[i]<<" ";
    	// }cout<<"\n";
    }
    
    int len = lower_bound(lis,lis+n,inf)-lis;
    memset(lis,inf,sizeof(lis));
    for(int i=0;i<n;i++){
    	l[i]=lower_bound(lis,lis+n,A[i])-lis;
    	lis[l[i]++] = A[i];
    	if(lower_bound(lis,lis+n,inf)-lis==len){
    		cout<<len<<"\n";
    		for(int i=0;i<len;i++){
    			cout<<lis[i]<<" ";
    		}
    		break;
    	}
    }

    return 0;
}
