    #include <bits/stdc++.h>
    #define ll long long
    #define ld long double 
    #define inf 0x3f3f3f3f
    #define fi first
    #define se second
    //#define cout cerr
    #define FILE "chonRobot" 
    template <class T> bool ckmin(T &a, const T &b) {return (a > b ? a = b, true : false); };
    template <class T> bool ckmax(T &a, const T &b) {return (a < b ? a = b, true : false); };
    using namespace std;
    //**Variable**//
    ll n;
    ll A[2101][2101];
    ll vis[2101][2101];
    ll par[10000006];
    ll sz[10000006];
    ll cur[10000006];
    ll timer = 0;
    ll ans = 1;
    //**Struct**//
    struct Edge{
        ll u, v, w;
    };
    vector<Edge> E;
    //**Function**//
    bool cmp(Edge a, Edge b){
        return a.w < b.w;
    }
    bool check(ll x, ll y){
        return (x > 0 && y > 0 && x <= n && y <= n);
    }
    ll convert(ll i, ll j){
        return i * n + j;
    }
    ll Find(ll u){
        if(cur[u] != timer){
            cur[u] = timer;
            par[u] = u;
            sz[u] = 1;
        }
        if(par[u] == u)return u;
        return u =  Find(par[u]);
    }
    bool Union(ll u, ll v){
        ll a = Find(u);
        ll b = Find(v);
        if(a == b) return false; 
        if(sz[a] < sz[b])swap(a,b);
        sz[a] += sz[b];
        // ans = max(ans, sz[a]);
        par[b] = a;
        return true;
    }
    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        // freopen(FILE".inp","w",stdout);
        freopen(FILE".inp","r",stdin);
        freopen(FILE".out","w",stdout);
        cin >> n;
        for(ll i = 1; i<=n; i++){
            for(ll j = 1; j<=n; j++){
                cin >> A[i][j];
            }
        }
        for(ll i = 1; i<=n; i++){
            for(ll j = 1; j<=n; j++){
                if(check(i + 1, j)){
                    E.push_back({convert(i,j), convert(i+1,j), abs(A[i][j] - A[i+1][j])});
                }
                if(check(i, j + 1)){
                    E.push_back({convert(i,j), convert(i,j+1), abs(A[i][j] - A[i][j+1])});
                }
            }
        }
        sort(E.begin(), E.end(), cmp);
        ll st;
        ll ed;
        for(ll i = 0; i<E.size(); i++){
            st = i;
            ed = i;
            while(E[ed].w == E[st].w && ed < E.size())ed++;
            timer++;
            for(ll j = st; j<ed; j++){
                Union(E[j].u, E[j].v);
                ans = max(ans, sz[Find(E[j].v)]);
                // ans = max(ans, sz[Find(E[j].v)]);
            }
            i = ed;
        }
        cout << ans;
        return 0;
    }
