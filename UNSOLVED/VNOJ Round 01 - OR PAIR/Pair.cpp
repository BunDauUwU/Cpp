#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "Pair" 
using namespace std;
//**Variable**//
ll n;
ll A[1000006];
//**Struct**//
struct Trie{
	struct Node{
		int val; 
		int ext;
		Node *child[2];
		Node(){
			child[0] = child[1] = NULL;
			val = ext = 0;
		}
	};
	Node* root = new Node();
	void add(ll a){
		Node* pos = root; 
		for(int i = 0; i<20; i++){
			int c = (a >> i);
			if(pos -> child[c] == NULL){
				pos -> child[c] = new Node();
			}
			pos = pos -> child[c];
			pos -> val ++;
		}
		pos -> ext ++;
	}
};
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin>>A[i];
	}	
 
    return 0;
}
