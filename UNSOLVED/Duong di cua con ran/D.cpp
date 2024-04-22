#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "snail" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int n;
int A[100005];
int f[16][100005];
vector <int> prime;
int isNotPrime[100005];
//**Struct**//

//**Function**//
void sang(){
	isNotPrime[0] = isNotPrime[1];
	for(ll i = 2; i<=10003; i++){
		if(isNotPrime[i])continue;
		prime.push_back(i);
		for(ll j = i*i; j<=10003; j+=i){
			isNotPrime[j] = 1;
		}
	}
}
void transf(int x){
	for(int i = 0; i<prime.size(); i++){
		int uwu = 0;
		while(x % prime[i] == 0){
			x/=prime[i];
			uwu++;
		}
		f[uwu][prime[i]]++;
		if(x == 1)break;
	}
	
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    sang();
    cin >> n;
    for(int i = 1; i<=n; i++){
    	cin >> A[i];
    	transf(A[i]);
    }
    int ans = 1;
   	for(auto it : prime){
   		for(int i = 0; i<=16; i++){
   			for(int j = 0; j<=16;j++){
   				
   			}
   		}
   	}
    return 0;
}
// minKc => (a-x)+(b-x)+..... = min
// a + b + c +... + x*n = min 
// a = số số nguyên tố sao cho a^p*b^k*.. 
// Tương tự vs b,c,...
// Tìm x: => 
// Mảng đánh dấu log(2),log(3),...
// Sweepline?