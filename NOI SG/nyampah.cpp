#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define debug(x) cout << #x << " => " << x << "\n"

#define fi first
#define se second

const int mod = 1e9 + 7;

int n, q;
vector <int> g[100005];
vector <pair<pair<int,int>,int>> edges;

int par[100005];
int anc[100005][20];

int tmr;
int in[100005], out[100005];

void euler(int pos, int prv){
    par[pos] = prv;
    in[pos] = ++tmr;
    anc[pos][0] = par[pos];
    for(int i = 1; i < 20; i++){
        anc[pos][i] = anc[anc[pos][i - 1]][i - 1];
    }
    for(auto i : g[pos]) if(i != par[pos]){
        euler(i, pos);
    }
    out[pos] = tmr;
}

struct node{
    int md, dist;
    bool grape;
};

node tree[400005];
int lazy[400005];

void push(int idx, int l, int r){
    if(lazy[idx]){
        if(l == r)
            tree[idx].dist += lazy[idx];
        tree[idx].md += lazy[idx];
        if(l != r){
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void anneal(int idx, int l, int r, int x, int y, int v){
    push(idx, l, r);
    if(l > r || l > y || r < x) return;
    if(l >= x && r <= y){
        lazy[idx] += v;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    anneal(idx * 2, l, mid, x, y, v);
    anneal(idx * 2 + 1, mid + 1, r, x, y, v);
    tree[idx].md = min(tree[idx * 2].md, tree[idx * 2 + 1].md);
}

void soak(int idx, int l, int r, int x){
    push(idx, l, r);
    if(l == r){
        tree[idx].grape ^= 1;
        if(tree[idx].grape)
            tree[idx].md = tree[idx].dist;
        else tree[idx].md = 1e18 + 7;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) soak(idx * 2, l, mid, x);
    else soak(idx * 2 + 1, mid + 1, r, x);
    push(idx * 2, l, mid);
    push(idx * 2 + 1, mid + 1, r);
    tree[idx].md = min(tree[idx * 2].md, tree[idx * 2 + 1].md);
}

int seek(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return 1e18 + 7;
    if(l >= x && r <= y) return tree[idx].md;
    int mid = (l + r) / 2;
    return min(seek(idx * 2, l, mid, x, y), seek(idx * 2 + 1, mid + 1, r, x, y));
}

int jarak(int idx, int l, int r, int x){
    push(idx, l, r);
    if(l == r) return tree[idx].dist;
    int mid = (l + r) / 2;
    if(x <= mid) return jarak(idx * 2, l, mid, x);
    else return jarak(idx * 2 + 1, mid + 1, r, x);
}

bool isParent(int u, int v){
    if(u == 0) return true;
    if(in[u] < in[v] && out[u] >= out[v])
        return true;
    return false;
}

int lca(int u, int v){
    if(u == v) return u;
    if(isParent(u, v)) return u;
    if(isParent(v, u)) return v;
    for(int i = 19; i >= 0; i--){
        if(!isParent(anc[u][i], v))
            u = anc[u][i];
    }
    return anc[u][0];
}

map <pair<int,int>,int> mp;
int grapeloc;
bool haveGrape[100005];

void solve(){
    cin >> n >> q;
    for(int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        edges.pb({{u, v}, w});
        g[u].pb(v);
        g[v].pb(u);
    }
    euler(1, 0);
    // for(int i = 1; i <= n; i++)
    //     cout << in[i] << " " << out[i] << "\n";
    for(int i = 1; i <= 400000; i++)
        tree[i].md = 1e18 + 7;
    for(auto i : edges){
        if(i.fi.fi == par[i.fi.se]){
            anneal(1, 1, n, in[i.fi.se], out[i.fi.se], i.se);
            mp[{i.fi.fi, i.fi.se}] = i.se;
        }
        else if(i.fi.se == par[i.fi.fi]){
            anneal(1, 1, n, in[i.fi.fi], out[i.fi.fi], i.se);
            mp[{i.fi.se, i.fi.fi}] = i.se;
        }
    }
    for(int t; q--;){
        cin >> t;
        if(t == 1){
            int u; cin >> u;
            if(grapeloc == -1){
                cout << -1 << "\n";
            }
            else{
                int res = jarak(1, 1, n, in[u]) + jarak(1, 1, n, in[grapeloc]) - 2 * jarak(1, 1, n, in[lca(u, grapeloc)]);
                cout << res << "\n";
            }
        }
        if(t == 2){
            int u; cin >> u;
            // debug(in[u]);
            soak(1, 1, n, in[u]);
            haveGrape[u] ^= 1;
            if(haveGrape[u])
                grapeloc = u;
            else grapeloc = -1;
        }
        if(t == 3){
            int a, b, w;
            cin >> a >> b >> w;
            if(a == par[b]){
                int d = w - mp[{a, b}];
                anneal(1, 1, n, in[b], out[b], d);
                mp[{a, b}] = w;
            }
            else if(b == par[a]){
                int d = w - mp[{b, a}];
                anneal(1, 1, n, in[a], out[a], d);
                mp[{b, a}] = w;
            }
        }
    }
}

/*
sub 1 brute
sub 2 use semacam dp on tree
sub 3 binlift
sub 4 lca
sub 5 tbd

EULER TREE!!!
*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}