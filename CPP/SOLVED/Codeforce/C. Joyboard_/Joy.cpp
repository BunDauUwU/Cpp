#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Joy" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t;
int n, m ,k;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n>>m>>k;
    	if(k==1){
            cout<<1<<"\n";
        }
        if(k==2){
            if(m<=n)cout<<m<<"\n";
            else cout<<n+ ((m-n)/n)<<"\n";
        }
        if(k==3){
            if(m<=n)cout<<0<<"\n";
            else cout<<m - n  - ((m-n)/n)<<"\n";
        }
        if(k>3){
            cout<<0<<"\n";
        }
    }
    
    return 0;
}
