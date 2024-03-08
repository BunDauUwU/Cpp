#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "k" 
using namespace std;
//**Variable**//
int n;
int A[300006];
int q;
int t,x,y,k;
int sz;
int T[175][10006];
int mxVal = 10000;
//**Struct**//

//**Function**//
void update(int t, int x, int v){
    while(t <= 174){
        int i = x;
        while( i <= mxVal){
            T[t][i] += v;
            i += i&-i;
        }
        t+=t&-t;
    }
}
int get(int t, int x){
    int res = 0;
    while(t > 0){
        int i = x;
        while( i > 0){
            res += T[t][i];
            i -= i&-i;
        }
        t-=t&-t;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    // freopen(FILE".inp","r",stdin);
    // freopen(FILE".out","w",stdout);
    cin>>n;
    sz = sqrt(n);
    for(int i = 1; i<=n; i++){
        cin>>A[i];
        update(i/sz + 1 - (i%sz == 0),A[i],1);
    }
    cin>>q;
    while(q--){
        cin>>t;
        if(!t){
            cin>>x>>y;
            update(x/sz + 1 - (x%sz == 0),A[x],-1);
            A[x] = y;
            update(x/sz + 1 - (x%sz == 0),A[x],1);
        }else{
            cin>>x>>y>>k;
            int L = x/sz + 1 - (x%sz == 0);
            int R = y/sz + 1 - (y%sz == 0);
            int ans = 0;
            if(L == R){
                for(int i = x; i<=y; i++){
                    ans += A[i] > k;
                }
                cout<<ans<<"\n";
                continue;
            }
            if(L+1 > R - 1 || k + 1 > mxVal)ans = 0;
            else{
                ans = get(R-1,mxVal) - get(L,mxVal) - get(R-1,k) + get(L,k);
            }
            for (int i=x; i<=L*sz; i++) ans += (A[i] > k);
            for (int i=(R-1)*sz+1; i<=y; i++) ans += (A[i] > k);
            cout<<ans<<"\n";
        }
    }
    return 0;
}