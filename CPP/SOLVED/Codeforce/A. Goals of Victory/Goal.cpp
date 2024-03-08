#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Goal" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t;
int n;
ll a[1000006];
int s=0,S=0;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	s = 0;
    	cin>>n;
    	for(int i=1;i<n;i++){
    		cin>>a[i];
    		// cout<<a[i];
    		s+=a[i];
    	}
 		if(s>=0){
 			cout<<-s<<"\n";
 		}
 		else{
 			cout<<-s<<"\n";
 		}
    }
    return 0;
}
