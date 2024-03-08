#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "IVECTOR" 
using namespace std;
//**Variable**//
int n;
int A[100005];
int t[100005];
int bit[100005];
int ans1[100005];
int ans2[100005];
bool used[100005];
//**Struct**//
struct query{
    int idx, val;
}T[100005];
struct query2{
    int idx, val;
}C[100005];
//**Function**//
bool cmp(query a, query b){
    return a.val < b.val;
}
bool cmp2(query2 a, query2 b){
    return a.val < b.val;
}
void update(int x, int val){
    // for(int i = x; i>0; i -= (i & -i))bit[i]+=val;
    for(int i = x; i<=100005; i += (i & -i))bit[i]+=val;
}
int get(int x){
    int ans = 0;
    // for(int i = x; i<=100005; i += (i & -i)){
        // ans += bit[i];
    // }
    for(int i = x; i>0; i -= (i & -i))ans+=bit[i];
    return ans;
}
int binary(int p){
    int l = 1, r = n;
    int k = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(get(m) >= p){
            k = m;
            r = m - 1;
        }
        else l = m +1;
    }
    return k;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(int i = 1; i<=n; i++){
    	cin>>A[i];
        T[i] = {i,A[i]};
    }
    for(int i = 1; i<=n; i++){
        ans1[A[i]] = (i-1) - get(A[i]);
        update(A[i],1);
    }
    for(int i = 1; i<=n; i++){
        cout<<ans1[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i<=n; i++){
        cin>>t[i];
    }
    memset(bit,0,sizeof(bit));
    for(int i = 1; i<=n; i++)update(i,1);
        // return 0;
    for(int i = 1; i<=n; i++){
        int j = binary(t[i] + 1);
        ans2[j] = i;
        update(j,-1);
    }
    for(int i =1; i<=n; i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}