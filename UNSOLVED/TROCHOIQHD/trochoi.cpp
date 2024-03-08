#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "trochoi" 
using namespace std;
//**Variable**//

//**Struct**//
struct Trie{
    struct Node{
        Node* child[2];
        int exist, cnt;

        Node() {
            for (int i = 0; i < 2; i++) child[i] = NULL;
            exist = cnt = 0;
        }
    };
 
    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };
 
    void add(int a) {
        Node* p = root;
        for(int i = 0; i<20; i++){
            int c = (a>>i)&1;
            if (p->child[c] == NULL) p->child[c] = new Node();
            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }
       
};
//**Function**//

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    
    
    return 0;
}
