#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "SECRCD" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int A[1000006];
bool isnotPrime[1000006];
ll MOD=1e9+7;
vector<int> prime(0);
ll m[1000006];
//**Function**//
void sang(){
    isnotPrime[0]=1;
    isnotPrime[1]=1;
    for(int i=2;i<=1000006;i++){
        if(!isnotPrime[i]){
            prime.push_back(i);
            for(int j=i*2;j<=1000006;j+=i){
                isnotPrime[j]=1;
            }
        }
    }
}
void cntFactor(ll a){
    ll cnt = 0;
    ll pos = 0;
    while(a!=1){
        while(a%prime[pos]!=0){
            pos++;
        }
        while(a%prime[pos]==0 && a!=1){
            a= a/prime[pos];
            cnt++;
        }
        m[prime[pos]]+=cnt;
        cnt = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    sang();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        cntFactor(A[i]);
    }
    ll res=1;
    for(auto it:prime){
        // cout<<it<<" "<<m[it]<<"\n";
        if(m[it]==0)continue; 
        res *= (m[it]+1);
        res%=MOD;
    }
    cout<<res;
    return 0;
}
