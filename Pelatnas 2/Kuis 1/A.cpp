#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, m, q;
vector <int> g[100005];

struct node{
    int par;
    set <int> child;
};

struct dsu_on_tree{
    node ds[100005];
    dsu_on_tree(){
        for(int i = 1; i <= 100000; i++){
            ds[i].par = i;
            ds[i].child.clear();
        }
    }
    int find(int u){
        if(ds[u].par == u)
            return u;
        return ds[u].par = find(ds[u].par);
    }
    int join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return 0;
        if(ds[u].child.size() >= ds[v].child.size()){
            // v to u
            for(auto i : ds[v].child)
                ds[u].child.insert(i);
            ds[u].child.erase(u);
            ds[u].child.erase(v);
            ds[v].par = u;
        }
        else{
            // u to v
            for(auto i : ds[u].child)
                ds[v].child.insert(i);
            ds[v].child.erase(v);
            ds[v].child.erase(u);
            ds[u].par = v;
        }
        return 1;
    }
} dsu;

struct dsu{
    int par[100005];
    dsu(){
        for(int i = 1; i <= 100000; i++)
            par[i] = i;
    }
    int find(int u){
        if(par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }
    int join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return 0;
        par[u] = v;
        return 1;
    }
} cycle_dsu;

bool vis[100005], vis2[100005];
int parent[100005];

void dfs(int pos, int par){
    if(vis2[pos]) return;
    if(vis[pos]){
        int cur_node = par;
        for(; cur_node != pos; cur_node = parent[cur_node])
            cycle_dsu.join(cur_node, pos);
        return;
    }
    parent[pos] = par;
    vis[pos] = 1;
    for(auto i : g[pos]) if(i != par){
        dfs(i, pos);
    }
    vis[pos] = 0;
    vis2[pos] = 1;
}

int modex(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res % mod;
}

int inv(int x){
    return modex(x % mod, mod - 2) % mod;
}

int dp[100005], ans[100005], root;

vector <int> pref[100005], suff[100005], srted[100005];

void dpdfs(int pos, int par){
    dp[pos] = 1;
    for(auto i : dsu.ds[pos].child){
        if(i != par){
            dpdfs(i, pos);
            (dp[pos] *= dp[i] + 1) %= mod;
            srted[pos].pb((dp[i] + 1) % mod);
            pref[pos].pb((dp[i] + 1) % mod);
            suff[pos].pb((dp[i] + 1) % mod);
        }
    }
}

void getans(int pos, int par, int carry){
    ans[pos] = dp[pos];
    int u = 1, v = 1, newCarry = carry;
    if(pos != root){
        int akarin = lower_bound(srted[par].begin(), srted[par].end(), (dp[pos] + 1) % mod) - srted[par].begin();
        if(akarin > 0 && akarin < srted[par].size())
            (u *= pref[par][akarin - 1]) %= mod;
        if(akarin >= 0 && akarin < srted[par].size() - 1)
            (v *= suff[par][akarin + 1]) %= mod;
        // updates u * v
        newCarry = (((u * v) % mod * carry) % mod + 1) % mod;
        (ans[pos] *= newCarry) %= mod;
    }
    for(auto i : dsu.ds[pos].child){
        if(i != par){
            getans(i, pos, newCarry % mod);
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        dsu.ds[u].child.insert(v);
        dsu.ds[v].child.insert(u);
    }
    // a node can either be combined or a child of capital
    // dp - accepts children of distance 1 or not
    for(int i = 1; i <= n; i++){
        dfs(i, -1);
    }
    // for(int i = 1; i <= n; i++)
    //     cout << cycle_dsu.find(i) << " ";
    // cout << "\n";
    for(int i = 1; i <= n; i++){
        int u = cycle_dsu.find(i);
        for(auto j : g[i]){
            if(u == cycle_dsu.find(j)){
                dsu.join(u, j);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        int u = dsu.find(i);
        if(vis[u] == false){
            vis[dsu.find(i)] = true;
            int u = dsu.find(i);
            set <int> tmp;
            for(auto j : dsu.ds[u].child){
                if(dsu.find(j) != u)
                    tmp.insert(dsu.find(j));
            }
            dsu.ds[u].child = tmp;
            // for(auto j : dsu.ds[u].child){
            //     cout << dsu.find(j) << " ";
            // }
            // cout << "\n";
        }
    }
    root = dsu.find(1);
    dpdfs(root, -1);
    for(int i = 1; i <= n; i++){
        sort(srted[i].begin(), srted[i].end());
        sort(pref[i].begin(), pref[i].end());
        sort(suff[i].begin(), suff[i].end());
        if(srted[i].empty()) continue;
        for(int j = 1; j < pref[i].size(); j++)
            (pref[i][j] *= pref[i][j - 1]) %= mod;
        for(int j = suff[i].size() - 1; j > 0; j--)
            (suff[i][j - 1] *= suff[i][j]) %= mod;
    }
    getans(root, -1, 1);
    for(int k, i = 1; i <= q; i++){
        cin >> k;
        k = dsu.find(k);
        cout << ans[k] % mod << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}