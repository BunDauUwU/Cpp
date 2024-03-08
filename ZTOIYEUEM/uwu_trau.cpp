#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5,K=1e9+7;
#define ll long long 
#define yes {cout<<"YES";return;}
#define no {cout<<"NO";return;}
#define srt(a,n) sort(a+1,a+n+1);
#define srt2(a,n,comp) sort(a+1,a+n+1,comp);
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
const ll L=1e18;
ll n,m,k;
ll a[N];
ll dp[N];
ll d[N][31];
ll mi[31];
ll f[N][31];
ll kq=0;
ll b[N];
void subfull()
{
    for (int i=1;i<=n;i++)
    {
        b[i]=i-a[i];
    }
    ll cnt=0;
    srt(b,n);
    b[0]=-1e9;
    for (int i=1;i<=n;i++)
    {
        if (b[i]!=b[i-1])
        {
            cnt++;
            dp[cnt]=b[i];
        }
    }
    for (ll i=1;i<=n;i++)
    {
        d[i][0]=a[i];
         ll j=lower_bound(dp+1,dp+cnt+1,i-a[i])-dp;
        for (ll l=min(i,k);l>=0;l--)
        {
            d[i][l]=f[j][l]+a[i];
            if (l!=0)
            d[i][l]=max(d[i][l],mi[l-1]+a[i]);
            
            mi[l]=max(mi[l],d[i][l]);
            f[j][l]=d[i][l];
        }
    }
    kq=0;
    for (ll i=1;i<=n;i++)
    {
        for (ll j=0;j<=k;j++)
        {
            kq=max(kq,d[i][j]);
        }
    }
    cout<<kq;
}
void solve()
{
 cin>>n>>k;
 for (int i=1;i<=n;i++)
 {
     cin>>a[i];
 }
     subfull();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("uwu.inp","r",stdin);
   freopen("uwu_trau.out","w",stdout);
int te=1;
//   cin>>te;
   while(te--)
   {
       solve();
       cout<<"\n";
   }
    return 0;
}
