#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define FILE "Alice" 
#define xiao cout
#define ciin cin
#define tt cout<<"TrangTrangVn❀";
#define f1(a,b) for(int i=a;i<=b;i++)
using namespace std;
//**Struct**//

//**Variable**//
ll n,m;
ll cost =0, cur = 1;
int r[100005],c[100005];//remain,cost
int d[100005],t[100005];//kind,number
//**Function**//
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q; 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		Q.push({c[i],i});
	}
	int k,q,q2;
	pair<int,int> tmp;
	for(int i=1;i<=m;i++){
		cin>>k>>q;
		cost=0;
		if(r[k]>=q){
			cost+=(r[k]-q)*c[k];
			r[k]-=q;
		}else{
			bool check = 0;
			if(Q.empty()){cout<<"0\n";continue;}
			q-=r[k];
			cost+= r[k]*c[k];
			r[k]=0;
			while(!Q.empty()){
				while(!Q.empty() && r[Q.top().second]==0)Q.pop();
				if(Q.empty())break;
				tmp = Q.top();
				if(q<= r[tmp.second]){
					check = 1;
					r[tmp.second]-=q;
					cost+= tmp.first*q;
					break;
				}else{
					cost+=1ll*r[tmp.second]*tmp.first;
					q-=r[tmp.second];
					r[tmp.second]=0;
					Q.pop();
				}

			}
			if(!check)cost =0;	
		}
		cout<<cost<<"\n";
	}
	
    
    return 0;
}
