#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "jellyB" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
ll t,n,m,k;
int J[55],G[55];
ll sumJ,sumG;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ciin>>t;
    while(t--){
        sumJ=0, sumG=0;
        ciin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>J[i];sumJ+=J[i];
        }
        for(int j=1;j<=m;j++){
            cin>>G[j];sumG+=G[j];
        }
        sort(J+1,J+n+1);
        sort(G+1,G+m+1);
        if(J[1]>=G[m]){
            if(k%2==1){
                cout<<sumJ<<"\n";continue;
            }else{
                cout<<sumJ-J[n]+G[1]<<"\n";continue;
            }
        }
        sumJ+= G[m]-J[1];
        if(k==1){
            cout<<sumJ<<"\n";continue;
        }
        if(J[1]<=G[1]){
            if(k%2==1){
                cout<<sumJ<<"\n";continue;
            }else{
                cout<<sumJ-G[m]+J[1]<<"\n";continue;
            }
        }else{
            if(k%2==1){
                cout<<sumJ<<"\n";continue;
            }
            else{
                cout<<sumJ-G[m]+G[1]<<"\n";continue;
            }
        }

        cout<<"\n";
    }
    return 0;
}
