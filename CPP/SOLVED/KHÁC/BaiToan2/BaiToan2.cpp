#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "BaiToan2" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,l;
int c[100005],dp[100005];
pair<int,int> tcase[100005];
vector<int>ans;
queue<int> q;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin>>n>>l;
	// memset(dp,inf,sizeof(dp));
    for(int i=1;i<=n;i++){
    	cin>>c[i];
    }
    dp[0]=0;
    for(int i=1;i<=l;i++){
    	dp[i] = dp[0]+c[i-0];
    	for(int j=1;j<=l;j++){
    		if(j<=i){
    			if(dp[i]==0){dp[i]=dp[j]+c[i-j];continue;}
    			if(dp[i]>dp[j]+c[i-j]){
    				dp[i] =dp[j]+c[i-j];
    				tcase[i]={j,i-j};
    			}
    			c[i]=dp[i];
    		}
    	}
    }
    // for(int i=0;i<=l;i++){
    	// cout<<dp[i]<<" ";
    // }
    // for(int i=1;i<=l;i++){
    	// cout<<tcase[i].first<<" "<<tcase[i].second<<"\n";
    // }
    cout<<dp[l]<<"\n";
    q.push(tcase[l].first);
    q.push(tcase[l].second);
    while(!q.empty()){
    	int t= q.front();
    	q.pop();
    	if(tcase[t].first){
    		q.push(tcase[t].first);
    	}else{
    		ans.push_back(t);
    	}
    	if(tcase[t].second){
    		q.push(tcase[t].second);
    	}else{
    		ans.push_back(t);
    	}
    }
    for(int i=0;i<ans.size();i+=2){
    	cout<<ans[i]<<" ";
    }
    return 0;
}
