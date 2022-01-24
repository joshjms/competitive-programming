#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, q, arr[100005], narr[100005];
vector <int> g[100005];

int pos[100005], par[100005], lmc[100005], rmc[100005]; 
// left most child and right most child
int order;

struct segment_tree{
    int tree[400005];
    int lazy[400005];
    void build(int idx, int l, int r){
        if(l > r || l <= 0 || r > n) return;
        if(l == r){
            tree[idx] = narr[l];
            return;
        }
        int md = (l + r) / 2;
        build(idx * 2, l, md);
        build(idx * 2 + 1, md + 1, r);
        tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % mod;
    }
    void push(int idx, int l, int r){
        if(lazy[idx] > 0){
            if(l < r){
                (lazy[idx * 2] += lazy[idx]) %= mod;
                (lazy[idx * 2 + 1] += lazy[idx]) %= mod;
            }
            (tree[idx] += lazy[idx] * (r - l + 1)) %= mod;
            lazy[idx] = 0;
        }
    }
    void upd(int idx, int l, int r, int x, int y, int v){
        if(l <= 0 || r > n) return;
        push(idx, l, r);
        if(l > r || l > y || r < x) return;
        if(l >= x && r <= y){
            (lazy[idx] += v) %= mod;
            push(idx, l, r);
            return;
        }
        int md = (l + r) / 2;
        upd(idx * 2, l, md, x, y, v);
        upd(idx * 2 + 1, md + 1, r, x, y, v);
        tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % mod;
    }
    int query(int idx, int l, int r, int x, int y){
        if(l <= 0 || r > n) return 0;
        push(idx, l, r);
        if(l > r || l > y || r < x) return 0;
        if(l >= x && r <= y) return tree[idx];
        int md = (l + r) / 2;
        return (query(idx * 2, l, md, x, y) + query(idx * 2 + 1, md + 1, r, x, y)) % mod;
    }
} segtree;

void bfsorder(){
    queue <int> bfs;
    bfs.push(1);
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        pos[node] = ++order;
        for(auto i : g[node]) if(i != par[node]){
            par[i] = node;
            bfs.push(i);
            if(!lmc[node]) lmc[node] = i;
            rmc[node] = i;
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfsorder();
    for(int i = 1; i <= n; i++)
        narr[pos[i]] = arr[i];
    segtree.build(1, 1, n);
    cin >> q;
    for(int t, x; q--;){
        cin >> t >> x;
        if(t == 1){
            int v = segtree.query(1, 1, n, pos[x], pos[x]);
            segtree.upd(1, 1, n, pos[par[x]], pos[par[x]], v);
            segtree.upd(1, 1, n, pos[lmc[x]], pos[rmc[x]], v);
        }
        else{
            int ans = (segtree.query(1, 1, n, pos[par[x]], pos[par[x]]) + segtree.query(1, 1, n, pos[lmc[x]], pos[rmc[x]])) % mod;
            cout << ans << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}