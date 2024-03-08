#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "dance" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
ll n,m,q;
ll b[100005],g[100005],l[1000006],r[1000006];
ll x,y;
int t;
//**Function**//
void solve(){
	cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>g[i];
    }
    sort(b+1,b+1+n);
    sort(g+1,g+1+m);
    cin>>q;
    while(q--){
    for(int i=1;i<=n;i++){
        l[i] = r[i] = 0;
        }
        cin>>x>>y;
        int j = 1;
        for(int i=n;i>=1;i--){
            while(b[i]*g[j]<x && j<=m)j++;
            if(b[i]*g[j]<x)continue;
            // if(b[i]*g[j]>y)continue;
            l[i] = j;
        }
        j = m;
        for(int i = 1;i<=n;i++){
            while(b[i]*g[j]>y && j>=1)j--;
            if(b[i]*g[j]>y)continue;
            // if(b[i]*g[j]<x)continue;
            r[i]=j;
        }
        ll ans = 0 ;
        for(int i=1;i<=n;i++){
            // cout<<r[i]<<" "<<l[i]<<" ";
            if (l[i] == 0 || r[i] == 0) continue;
            ans+=r[i]-l[i]+1;
        }
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
