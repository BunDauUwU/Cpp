#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Robot" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int A[10000];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n; 
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    int s = 0, res = 0;
    while (true) {
        for (int i = 1; i <=n; i++)
            if (A[i] <= s) A[i] = n + 1, s++;
        if (s == n) break;
        res++;
        for (int i = n ; i >= 1; i--)
            if (A[i] <= s) A[i] = n + 1, s++;
        if (s == n) break;
        res++;
    }
    cout << res << endl;    
    return 0;
}
