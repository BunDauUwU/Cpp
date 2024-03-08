#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Restoring" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t,n,b[100005];
int m[100005];
int limit =0;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	vector<int> s(0);
    	memset(m,0,sizeof(m));
    	cin>>n;
    	limit = 2*n;
    	for(int i=1;i<=n;i++){
    		cin>>b[i];
    		m[b[i]]++;
    	}
    	for(int i=1;i<=n;i++){
    		s.push_back(b[i]);
    		for(int j=b[i];j<=2*n;j++){
    			if(!m[j]){
    				s.push_back(j);
    				m[j]=1;
    				break;
    			}
    		}
    	}
    	if(s.size()<2*n){
    		cout<<"-1\n";
    		continue;
    	}
    	for(auto it : s){
    		cout<<it<<" ";
    	}
    	cout<<"\n";
    }
    
    return 0;
}
