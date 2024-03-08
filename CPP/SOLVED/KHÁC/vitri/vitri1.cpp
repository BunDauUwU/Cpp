#include <iostream>
#include<vector>
#define ll long long 
#define FILE "VITRI" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,k,x;
int A[100000];
vector<int> ans(0);
//**Function**//
void solve(int l,int r,int id){
    if(id>k)return ;
    int mid = 0, val = 0, pre = 1e9;
    if(id%2==0){
        for(int i=l;i<=r;i++){
        // cout<<A[i]<<" ";
            val=max( A[i]-A[l], A[r-1]-A[i] );
            if(val < pre){
                pre = val;
                mid = i;
            }
        }   
    }else{
        for(int i=l;i<=r;i++){
        // cout<<A[i]<<" ";
        val=max( A[i]-A[l+1], A[r]-A[i] );
        if(val < pre){
            pre = val;
            mid = i;
        }
    }
    }
    // cout<<"\n";
    // cout<<mid<<" ";
    ans.push_back(mid);
    solve(l, mid, id*2);
    solve(mid+1, r, id*2+1);
}
// 6 3
// 5 6 12 19 20 27
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    solve(1,n,1);
    sort(ans.begin(),ans.end());
    // cout<<ans.size();
    for(auto it : ans){
        cout<<it<<"\n";
    }
  return 0;
}