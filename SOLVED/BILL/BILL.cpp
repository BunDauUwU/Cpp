#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "BILL" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//
struct axis{
    ld x, y;
    ld w;
};
//**Variable**//
int n;
ld hx,hy;
ld mx1,my1,mx2,my2;
ld x,y,a,b,c;
ld ans =0;
vector<axis> g(0);
//**Function**//
bool cmp(axis a, axis b){
    return a.w < b.w;
}
axis distance(ld a, ld b){
    axis e;
    e.x = a; e.y = b; e.w = sqrt(abs((a-hx)*(a-hx))+abs((b-hy)*(b-hy)) ); 
    return e;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    cout<<fixed<<setprecision(4)<<"\n";
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>hx>>hy;
    for(int i=1;i<=n;i++){
    	cin>>x>>y;
    	g.push_back(distance(x,y));
    }
    sort(g.begin(),g.end(),cmp);
    a = g[1].y-g[0].y;
    b = g[1].x-g[0].x;
    c = -(g[0].y*(g[1].x-g[0].x)) + g[0].x*(g[1].y-g[0].y);
    ans = abs(a*hx+b*hy+c)/sqrt(a*a+b*b);
    cout<<ans;
  return 0;
}