#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "FROG" 
using namespace std;
//**Variable**//
ll n, d;
ll A[1000006];
ll B[1000006];
ll ans = 0;
ll fA[1000006];
ll fB[1000006];
deque<ll> qA;
deque<ll> qB;
deque<ll> mxA;
deque<ll> mxB;
//**Struct**//

//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);	
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin>>n>>d;
    for(int i = 1; i<=n; i++){
    	cin>>A[i];
    	if(A[i] > 0){
    		ans += A[i];
    		A[i] = 0;
    	}
    }
    for(int i = 1; i<=n; i++){
    	cin>>B[i];
    	if(B[i] > 0){
    		ans += B[i];
    		B[i] = 0;
    	}
    }
    ans = ans + A[1] + B[1] + A[n] + B[n];
    A[1] = B[1] = A[n] = B[n] = 0;
    qA.push_back(1);
    qB.push_back(1);
    mxA.push_back(1);
    mxB.push_back(1);
    for(int i = 2; i<=n; i++){
    	while(qA.size() && qA.front() < i - d)qA.pop_front();
    	while(qB.size() && qB.front() < i - d)qB.pop_front();
    	while(mxA.size() && mxA.front() < i - d)mxA.pop_front();
    	while(mxB.size() && mxB.front() < i - d)mxB.pop_front();

    	fA[i] = fA[qA.front()] + B[mxB.front()] + A[i];
    	fB[i] = fB[qB.front()] + A[mxA.front()] + B[i];

    	fA[i] = max(fA[i], fB[qB.front()] + A[i]);
    	fB[i] = max(fB[i], fA[qA.front()] + B[i]);

    	while(qA.size() && fA[qA.back()] < fA[i]) qA.pop_back();
    	qA.push_back(i);
    	while(qB.size() && fB[qB.back()] < fB[i]) qB.pop_back();
    	qB.push_back(i);
    	while(mxA.size() && A[mxA.back()] < A[i]) mxA.pop_back();
    	mxA.push_back(i);
    	while(mxB.size() && B[mxB.back()] < B[i]) mxB.pop_back();
    	mxB.push_back(i);

    }
    ans = ans + max(fA[n],fB[n]);
    cout<<ans;
    return 0;
}
