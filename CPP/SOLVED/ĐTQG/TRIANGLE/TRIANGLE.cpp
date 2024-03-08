#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "TRIANGLE" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
int n,idx;
ll res = 0;
int A[100005]; 
char s;
vector<int> s1,s2,s3;
vector<int> f,t;
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s;
    	cin>>A[i];
    	if(s =='r') s1.push_back(A[i]);
    	if(s =='g') s2.push_back(A[i]);
    	if(s =='b') s3.push_back(A[i]);
    }
    // r.push_back(0);g.push_back(0);b.push_back(0);
    if(s1.size()<s2.size())swap(s1,s2);
    if(s1.size()<s3.size())swap(s1,s3);
    for(int i=0;i<s2.size();i++){
        for(int j=0;j<s3.size();j++){
            f.push_back(abs(s2[i]-s3[j]));
            t.push_back(s2[i]+s3[j]);
        }
    }
    sort(t.begin(),t.end());
    sort(f.begin(),f.end());
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<f.size();j++){
            if(f[j]>=s1[i]){
                break;
            }
            idx = lower_bound(t.begin(),t.end(),s1[i])-t.begin()+1;
            res+= s1.size()-idx;
        }
    }
    cout<<res;

    return 0;
}

