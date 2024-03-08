#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "CHUPANH" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,a,b,len =0,ans =1e9;
vector<pair<int,int>> t(0);
set<int> S;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>b;
    	t.push_back({a,b});
        S.insert(b);
    }
    len =S.size();
    t.push_back({-1,-1});
    sort(t.begin(),t.end());
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(t[i].second);
        for(int j=i+1;j<=n;j++){
            if(t[i].second!=t[j].second){
                s.insert(t[j].second);
            }else{continue;}
            if(s.size()==len){
                ans= min(ans,t[j].first-t[i].first);
                s.clear();
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
