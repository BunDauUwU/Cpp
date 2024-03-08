#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "QUATET" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int k,x,y,u,v;
ll len;
int thick = 1;
int z1=1,z2=1;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>k>>x>>y>>u>>v;
    len = pow(2,k);
    int maxthick = len*len;
    for(int i=1;i<=k;i++){
        len/=2;
        if(x>len-1){
            x = 2*len -x -1;
            z1 = thick+(thick-z1)+1; 
        }
        if(u>len-1){
            u = 2*len -u -1;
            z2 = thick+(thick-z2)+1;
        }
        thick*=2;
        cout<<z1<<" "<<z2<<"\n";
        if(y<=len-1){
            y = 2*len -y -1;
            z1 = thick+(thick-z1)+1; 
        }
        else{
            y = y-len;
        }
        if(v<=len-1){
            v = 2*len -v -1;
            z2 = thick+(thick-z2)+1;
        }else{
            v = v-len;
        }
        thick*=2;
        // cout<<z1<<" "<<z2<<"\n";
    }
    if(z1<=z2)swap(z1,z2);
    cout<<maxthick-z1<<" "<<maxthick-z2;
  return 0;
}