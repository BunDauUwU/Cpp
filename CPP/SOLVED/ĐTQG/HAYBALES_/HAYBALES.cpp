#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "HAYBALES" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
ll x=0;
ll moveup=0, movedown=0;
int A[100005];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ciin>>n;
    for(int i=1;i<=n;i++){
    	cin>>A[i];
    	x+=A[i];
    }
    x/=n;
    for(int i=1;i<=n;i++){
    	if(A[i]>x){
    		moveup+=(A[i]-x);
    	}
    	if(A[i]<x){
    		movedown+=(x-A[i]);
    	}
    }
    cout<<min(movedown,moveup)<<"\n";
    return 0;
}
