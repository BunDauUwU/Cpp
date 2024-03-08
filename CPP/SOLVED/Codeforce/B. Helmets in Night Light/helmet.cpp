#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "helmet" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int t,n ,p;
pair<int,int> a[100005];
int yet[100005];
int ans = 0;
//**Function**//
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>t;
    while(t--){
    	ans = 0;
    	cin>>n>>p;
    	for(int i=1;i<=n;i++){
    		cin>>a[i].first;
    	}
    	for(int i=1;i<=n;i++){
    		cin>>a[i].second;
    	}
    	sort(a+1,a+1+n,cmp);
    	int free = 0;
    	for(int i=0;i<=n;){
    		if(a[i+1].second>=p ){
    			ans+= max(n-i-free,0)*p;
    			break;
    		}
            ans+=p;
            if(free){ans-=p;free--;}
            i++;
            if(i+free+a[i].first<n){
                ans+=a[i].first*a[i].second;
                free++;
                n-=a[i].first;
                n+=1;
            }
            else{
                ans+= (n-i-free)*a[i].second;
                break;
            }
    	    
    	}
    	cout<<ans<<"\n";
    }
    
    return 0;
}
