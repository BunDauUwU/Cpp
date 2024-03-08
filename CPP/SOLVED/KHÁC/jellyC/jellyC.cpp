#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "jellyC" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t,cnt=0;
int m=0,n=0, a,b,c=0;
bool check=0;
//**Function**//
int OrderPower( int a){
    int cnt = 0;
    while(a>1){
        if(a%2==1) cnt++;
        a/=2;
    }
    return cnt;
} 
bool isPower (int a){
    if(a==0) return 0;
    if((a&(~(a-1)))==a){
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    
    cin>>t;
    while(t--){  	
    	cin>>n>>m;
        // cout<<"{"<<n<<","<<m<<"}";
        n=n%m;
        // cout<<n<<"|";
        c = gcd(n,m);
        a = n/c; 
        b = m/c;
        // cout<<n;
        if(!isPower(b))cout<<"-1\n";
        else{cout<< 1ll*__builtin_popcount(a)*m-n <<"\n";}
    }
    return 0;
}
