#include <bits/stdc++.h>
#define ll long long
#define ld long double 
#define inf 0x3f3f3f3f
#define fi first
#define se second
//#define cout cerr
#define FILE "m" 
template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
using namespace std;
//**Variable**//
int n;
int A[500005];
int C[500005];
int one[500005];
int two[500005];
int three[500005];
int four[500005];
//**Struct**//
struct BitUp{
    int bit[500005];
    void update(int x, int val){
        for(int i = x; i<=n; i+=i & (-i)){
            ckmax(bit[i], val); 
        }
    }
    int get(int x){
        // x+=2;
        int res = -1e9;
        for(int i = x; i>0; i-=i&(-i)){
            ckmax(res, bit[i]);
        }
        return res; 
    }
};
struct BitDown{
    int bit[500005];
    void update(int x, int val){
        for(int i = x; i>0; i-=i & (-i)){
            ckmax(bit[i], val); 
        }
    }
    int get(int x){
        x+=2;
        int res = -1e9;
        for(int i = x; i<=n; i+=i&(-i)){
            ckmax(res, bit[i]);
        }
        return res;
    }
};
BitUp st, rd;
BitDown nd, th;
//**Function**//
void compress(){
    vector<pair<int,int>> elem;
    elem.push_back({-1e9,0});
    for(int i = 1; i<=n; i++){
        elem.push_back({A[i], i});
    }
    sort(elem.begin(), elem.end());
    int gr = 0;
    for(int i = 1; i<=n; i++){
        if(elem[i].fi != elem[i-1].fi) C[elem[i].se] = ++gr;
        C[elem[i].se] = gr; 
    }
}                   
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen(FILE".inp","w",stdout);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n; 
    for(int i = 1; i<=n; i++){
        cin >> A[i];
    }
    compress();
    for(int i = 1; i<=n; i++){
        one[i] = st.get(C[i]) + 1;
        if(one[i] > 0)st.update(C[i] + 1, one[i]); 
    }
    for(int i = 1; i<=n; i++){
        two[i] = nd.get(C[i]) + 1;
        if(two[i] > 2)nd.update(C[i] + 1, two[i]);
        if(one[i] > 1)nd.update(C[i] + 1, one[i]);
    }
    for(int i = 1; i<=n; i++){
        three[i] = rd.get(C[i]) + 1;
        if(three[i] > 3)rd.update(C[i] + 1, three[i]);
        if(two[i] > 2)rd.update(C[i] + 1, two[i]);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, four[i] = (th.get(C[i]) + 1));
        if(four[i] > 4)th.update(C[i] + 1, four[i]);
        if(three[i] > 3)th.update(C[i] + 1, three[i]);
    }
    cout << ans;
    return 0;
}
