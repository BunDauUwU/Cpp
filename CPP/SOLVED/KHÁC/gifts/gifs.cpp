#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "gifts" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,s,x,y,tmp,ans=0,cnt=0;
pair<int,int> tcase[1000006];
//**Function**//
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin>>n>>s; 
	tmp=s;   
    for(int i=1;i<=n;i++){
    	cin>>x>>y;
    	tcase[i].first=x+y;
    	tcase[i].second=x/2;
    }
    sort(tcase+1,tcase+1+n);
    for(int i=1;i<=n;i++){
    	cnt=0;
    	tcase[i].first -= tcase[i].second;
    	tmp=s;
    	tmp-=tcase[i].first;
    	for(int j=1;j<=n && tmp>0;j++){
    		if(i==j)continue;
    		tmp -=tcase[j].first;
    		cnt++;
    	}
    	ans = max(ans,cnt);
    	tcase[i].first+=tcase[i].second;
    }
    cout<<ans;
    return 0;
}
