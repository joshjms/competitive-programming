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

int tmr;
int in[100005], out[100005];

void euler(int pos, int prv){
    par[pos] = prv;
    in[pos] = ++tmr;
    for(auto i : g[pos]) if(i != par[pos]){
        euler(i, pos);
    }
    out[pos] = tmr;
}

struct node{
    int md = 1e18 + 7;
    int dist = 0;
    bool grape = 0;
};

node tree[400005];
int lazy[400005];

void push(int idx, int l, int r){
    if(lazy[idx]){
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
        if(tree[idx].grape == 1)
            tree[idx].md = tree[idx].dist;
        else tree[idx].md = 1e18 + 7;
    }
    int mid = (l + r) / 2;
    if(x <= mid) soak(idx * 2, l, mid, x);
    else soak(idx * 2 + 1, mid + 1, r, x);
    tree[idx].md = min(tree[idx * 2].md, tree[idx * 2 + 1].md);
}

int seek(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return 1e18 + 7;
    if(l >= x && r <= y) return tree[idx].md;
    int mid = (l + r) / 2;
    return min(seek(idx * 2, l, mid, x, y), seek(idx * 2 + 1, mid + 1, r, x, y));
}

map <pair<int,int>,int> mp;

void solve(){
    cin >> n >> q;
    for(int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        edges.pb({{u, v}, w});
        g[u].pb(v);
        g[v].pb(u);
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