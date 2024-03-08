#include <bits/stdc++.h>
#include <string>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "NUMMAX" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
string s,f;
string ans;
ll dp[1005][1005];
vector<int> nearS[11],nearF[11];
// int nearS[11],nearF[11];
ll mx=0;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>s>>f;
    memset(nearS,0,sizeof(nearS));
    memset(nearF,0,sizeof(nearF));
    // cout<<s<<" "<<f<<" ";
    reverse(s.begin(),s.end());
    reverse(f.begin(),f.end());
    for(int i=0;i<s.size();i++){
    	for(int j=0;j<f.size();j++){
    		if(s[i]==f[j]){
    			dp[i+1][j+1]=dp[i][j]+1;
                nearS[ int(s[i]-'0')].push_back(i+1);                    
                nearF[ int(f[j]-'0')].push_back(j+1);
                // nearS[ int(s[i]-'0')]=(i+1);                    
                // nearF[ int(f[j]-'0')]=(j+1);
       		}
    		else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    for(int k=9;k>=0;k--){
        sort(nearS[k].begin(),nearS[k].end());
        sort(nearF[k].begin(),nearF[k].end());
    }
    // cout<<s<<"\n"<<f<<"\n";
        int cnt;
        int l,r;
        int i=s.size()+1,j=f.size()+1;
        dp[i][j]=dp[i-1][j-1];
        cnt = dp[i][j];
        while(dp[i][j]>0 && cnt>0){
            // cout<<dp[i][j];
            // cout<<i<<" "<<j<<"|"<<cnt<<"\n";
            for(int k=9;k>=0;k--){
                if(nearS[k].size()==0 || nearF[k].size()==0)continue;
                l=nearS[k].back();r=nearF[k].back();
                while(l>=i && nearS[k].size()){
                    nearS[k].pop_back();
                    l=nearS[k].back();
                    if(l<i)break;
                }
                while(r>=j && nearF[k].size()){
                    nearF[k].pop_back();
                    r=nearF[k].back();
                    if(r<j){
                        break;
                    }
                }
                // cout<<l<<" "<<r<<":"<<dp[l][r]<<"="<<s[l-1]<<"\n";
                if(nearS[k].size()==0 || nearF[k].size()==0)continue;
                if(dp[l][r]==cnt){
                    // cout<<"\n------\n";
                    ans+= s[l-1];
                    i = l;
                    j = r;
                    break;
                }
            }
            cnt--;
        }
    while(ans[0]=='0'){
        ans.erase(0,1);
    }
    cout<<ans;
    
    return 0;
}
