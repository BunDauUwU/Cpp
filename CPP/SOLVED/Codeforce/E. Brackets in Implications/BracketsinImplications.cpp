#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "BracketsinImplications" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n;
int A[100005],B[100005];
bool imp = 0;
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
    if(A[n]==1)cout<<"NO";
    else{
    	if(n==2){
    		if(A[n-1]==0){
    			cout<<"NO\n";
    		}else{
    			cout<<"YES\n";
    			for(int i=1;i<n;i++){
    				cout<<A[i]<<"->";
    			}cout<<A[n];
    		}
    		return 0;
    	}
    	if(n==1){
    		cout<<"YES\n";
    		cout<<A[n];
    		return 0;
    	}
    	if(A[n-1]==1){
    		cout<<"YES\n";
    		for(int i=1;i<n;i++){
    			cout<<A[i]<<"->";
    		}
    		cout<<A[n];
    		return 0;
    	}
    	if(A[n-1]==0){
    		if(A[n-2]<=A[n-1]){
    			cout<<"YES\n";
    			for(int i=1;i<n-2;i++){
    				cout<<A[i]<<"->";
    			}
    			cout<<"("<<A[n-2]<<"->"<<A[n-1]<<")->"<<A[n];
    		}
    		else{
    			int tmp=0;
    			for(int i=n-3;i>=1;i--){
    				if(A[i]==0){
    					tmp=i;
    					break;
    				}
    			}	
    			if(tmp!=0){
    				cout<<"YES\n";
    				for(int i=1;i<tmp;i++){
    					cout<<A[i]<<"->";
    				}
    				cout<<"("<<A[tmp]<<"->(";
    				for(int i=tmp+1;i<n-1;i++){
    					cout<<A[i]<<"->";
    				}
    				cout<<0<<"))->"<<A[n];
    			}else{
    				cout<<"NO\n";
    			}
    			return 0;
    		}
    	}
    }
    return 0;
}
