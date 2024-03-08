#include <bits/stdc++.h>
#define int long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "BANDUA" 
using namespace std;
//**Variable**//
int n;
int A[1000006];
stack<int> st;
//**Struct**//
struct plank{
	int l, r;
}P[1000006];
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
    	cin>>A[i];
    	// cnt[i] = 1;
    }
    //cnt = r - l + 1
    A[0] = 0;
    st.push(0); 
    for(int i = 1; i<=n; i++){
    	while(st.top() != 0 && A[st.top()]>=A[i])st.pop();
    	P[i].l = st.top() + 1;
    	st.push(i);
    }
    while(st.size())st.pop();
    A[n+1] = 0;
    st.push(n+1);
    for(int i = n; i>=1; i--){
    	while(st.top() != n+1 && A[st.top()]>=A[i])st.pop();
    	P[i].r = st.top();
    	st.push(i);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
    	// cout<<P[i].r<<" "<<P[i].l<<"\n";
    	if(A[i] <= P[i].r - P[i].l) ans = max(ans, A[i]);
    }
    cout<<ans;

    return 0;
}

