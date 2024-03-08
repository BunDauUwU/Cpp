#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "photo" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,k;
int a,b,cnt =0;
map<int,int> m;
vector<int> t;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin>>n>>k;    
    for(int i=1;i<=k;i++){
    	cin>>a>>b;
        m[a]=a;
    	m[b]=a;
        t.push_back(a);
        t.push_back(b);
    }
    t.push_back(0);
    sort(t.begin(),t.end());
    int a = 1;
    int b = 2*k;
    for(int i=1;i<=2*k;i++){
        a=i;
        for(int j=i+1;j<=b;j++){
            if(m[t[i]]==m[t[j]]){
                b= j-1;
                break;
            }
        }
        if(a>=b){
            cnt++;
            b=2*k;
        }
    }
    cout<<cnt;
    return 0;
}
