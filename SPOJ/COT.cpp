#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m;

struct node{
    node *left = NULL;
    node *right = NULL;
    int val = 0;
    node(int v){
        val = v;
    }
    node(node *lc, node *rc){
        left = lc;
        right = rc;
        if(lc) val += lc->val;
        if(rc) val += rc->val;
    }
};

node* build(int l, int r){
    if(l == r){
        return new node(0);
    }
    int md = (l + r) / 2;
    return new node(build(l, md), build(md + 1, r));
}

node* upd(node *cur, int l, int r, int x, int v){
    if(l == r){
        return new node(cur->val + v);
    }
    int md = (l + r) / 2;
    if(x <= md) return new node(upd(cur->left, l, md, x, v), cur->right);
    else return new node(cur->left, upd(cur->right, md + 1, r, x, v));
}

int query(node *u, node *v, node *lca, node *parlca, int l, int r, int k){
    if(l == r)
        return l;
    int md = (l + r) / 2;
    int cnt = u->left->val + v->left->val - lca->left->val - parlca->left->val;
    if(cnt >= k)
        return query(u->left, v->left, lca->left, parlca->left, l, md, k);
    else return query(u->right, v->right, lca->right, parlca->right, md + 1, r, k - cnt);
}

pair<int,int> a[100005];
int inp[100005], arr[100005];

vector <int> g[100005];
int par[100005][25];
int etr[100005], ext[100005], tmr, tmr2;

node* roots[100005];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
        inp[i] = a[i].fi;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        arr[a[i].se] = i;
    }
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    function <void(int,int)> getParent = [&](int ix, int parent){
        par[ix][0] = parent;
        for(int i = 0; i < 20 && par[par[ix][i]][i] != -1; i++){
            par[ix][i + 1] = par[par[ix][i]][i];
        }
    };
    roots[0] = build(1, n);
    function <void(int,int)> dfs = [&](int pos, int parent){
        etr[pos] = ++tmr;
        getParent(pos, parent);
        roots[pos] = upd(roots[parent], 1, n, arr[pos], 1);
        for(auto i : g[pos]) if(i != parent){
            dfs(i, pos);
        }
        ext[pos] = ++tmr2;
    };
    dfs(1, 0);
    function <int(int, int)> lca = [&](int u, int v){
        if(etr[u] <= etr[v] && ext[u] >= ext[v])
            return u;
        if(etr[v] <= etr[u] && ext[v] >= ext[u])
            return v;
        for(int i = 20; i >= 0; i--){
            if(par[u][i] != 0 && !(etr[par[u][i]] <= etr[v] && ext[par[u][i]] >= ext[v])){
                u = par[u][i];
            }
        }
        return par[u][0];
    };
    for(int i = 1, u, v, k; i <= m; i++){
        cin >> u >> v >> k;
        int idx = query(roots[u], roots[v], roots[lca(u, v)], roots[par[lca(u, v)][0]], 1, n, k);
        cout << a[idx].fi << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}