#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "cowrow" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,x,ans=1,maxC=0;
int A[1000006],cnt[1000006];
map<int,map<int,int>> m;
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
    	cnt[A[i]]=1;
    }
    for(int i=3;i<=n;i++){
    	if(A[i]==A[i-1]){
    		cnt[A[i]]++;
    	}
    	if(A[i]==A[i-2] && A[i-1]!=A[i]){
    		m[A[i]][A[i-1]]++;
    	}
    }	
    set<int> s(A+1,A+1+n);
	for(auto i:s){
		for(auto j:s){
			if(i==j)continue;
			m[i][j]+=cnt[i];
			ans=max(m[i][j],ans);
		}
	}

    cout<<ans;
    return 0;
}
