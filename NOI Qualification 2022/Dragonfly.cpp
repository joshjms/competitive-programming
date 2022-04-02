#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

// #define gc getchar_unlocked
// int input(){
//     char c = gc(); bool neg = false;
//     for(; c < '0'||'9' < c; c = gc())
//         if(c == '-') neg=true;
//     int x = c - '0'; c = gc();
//     for(; '0' <= c && c <= '9'; c = gc())
//         x = (x << 1) + (x << 3) + (c - '0');
//     if(neg) x = -x;
//     return x;
// }

int n, d, b[200005], s[200005], h[2000005];
vector <int> df[200005];
vector <int> g[200005];

int par[200005];

struct persistent_segment_tree {
    struct node {
        int v;
        node * left, * right;
        node () : v(0), left(NULL), right(NULL) {};
        node (int val) : v(val), left(NULL), right(NULL) {};
        node (node * lc, node * rc) {
            left = lc, right = rc;
            v = 0;
            if(left) v += left -> v;
            if(right) v += right -> v;
        }
    };
    vector <node*> roots;
    node * build(int l, int r) {
        if(l == r) return new node(0);
        int mid = (l + r) / 2;
        return new node(build(l, mid), build(mid + 1, r));
    }
    node * upd(node * cur, int l, int r, int x) {
        if(l == r) return new node(cur -> v + 1);
        int mid = (l + r) / 2;
        if(x <= mid) return new node(upd(cur -> left, l, mid, x), cur -> right);
        else return new node(cur -> left, upd(cur -> right, mid + 1, r, x));
    }
    int query(node * cur, int l, int r, int x, int y) {
        if(l > r || l > y || r < x) return 0;
        if(l >= x && r <= y) return cur -> v;
        int mid = (l + r) / 2;
        return query(cur -> left, l, mid, x, y) + query(cur -> right, mid + 1, r, x, y);
    }
} perstree;

struct fenwick_tree{
    int bit[200005];
    int sum(int idx){
        int sum = 0;
        for(; idx >= 1; idx -= (idx & -idx))
            sum += bit[idx];
        return sum;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
    void upd(int idx, int val){
        for(; idx <= n; idx += (idx & -idx))
            bit[idx] += val;
    }
} fwt;

int tmr, in[200005], out[200005];
int clr[200005];
int parclr[200005];
vector <int> chclr[200005];

void dfs(int pos, int par) {
    in[pos] = ++tmr;
    parclr[pos] = clr[s[pos]];
    clr[s[pos]] = pos;
    for(int c : g[pos]) if(c != par) {
        dfs(c, pos);
    }
    out[pos] = tmr;
    clr[s[pos]] = parclr[pos];
}

int t[200005];

// ah shit hld
// dear gods of kwok pls bless me
// as i try to implement this

int parent[200005], depth[200005], heavy[200005], head[200005], pos[200005];
int cur_pos;

int hld(int pos){
    int size = 1;
    int max_c_size = 0;
    for(auto c : g[pos]) if(c != parent[pos]) {
        parent[c] = pos;
        depth[c] = depth[pos] + 1;
        int c_size = hld(c);
        size += c_size;
        if(c_size > max_c_size)
            max_c_size = c_size, heavy[pos] = c;
    }
    return size;
}

void decompose(int v, int h){
    head[v] = h, pos[v] = ++cur_pos;
    if(heavy[v])
        decompose(heavy[v], h);
    for(auto c : g[v]){
        if(c != parent[v] && c != heavy[v]){
            decompose(c, c);
        }
    }
}

int query(int a, int b) {
    int res = 0;
    for(; head[a] != head[b]; b = parent[head[b]]) {
        if(depth[head[a]] > depth[head[b]])
            swap(a, b);
        res += fwt.sum(pos[head[b]], pos[b]);
    }
    if(depth[a] > depth[b])
        swap(a, b);
    res += fwt.sum(pos[a], pos[b]);
    return res;
}

vector <int> dragon[2000005];

void solve () {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) 
        cin >> b[i];
    for(int i = 1; i <= n; i++) 
        cin >> s[i];
    for(int i = 1; i <= d; i++)
        cin >> h[i];
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++) {
        if(parclr[i]) chclr[parclr[i]].pb(i);
    }
    perstree.roots.pb(perstree.build(1, n));
    for(int i = 1; i <= d; i++) {
        perstree.roots.pb(perstree.upd(perstree.roots.back(), 1, n, in[h[i]]));
    }
    memset(t, -1, sizeof(t));
    for(int i = 1; i <= n; i++) {
        int l = 0, r = d;
        while(l <= r) {
            int mid = (l + r) / 2;
            int res = perstree.query(perstree.roots[mid], 1, n, in[i], out[i]);
            if(res >= b[i])
                r = mid - 1, t[i] = mid;
            else l = mid + 1;
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << t[i] << " ";
    // cout << "\n";
    hld(1);
    decompose(1, 1);
    for(int i = 1; i <= n; i++) {
        if(parclr[i] == 0) {
            fwt.upd(pos[i], 1);
            if(t[i] != -1) dragon[t[i]].pb(i);
        }
    }
    for(int i = 1; i <= d; i++) {
        for(int j = 0; j < dragon[i - 1].size(); j++) {
            int node = dragon[i - 1][j];
            fwt.upd(pos[node], -1);
            for(auto c : chclr[node]) {
                fwt.upd(pos[c], 1);
                if(t[c] != -1) dragon[max(t[c], i - 1)].pb(c);
            }
        }
        cout << query(1, h[i]) << " ";
        // for(int j = 2; j <= n; j++)
        //     cout << query(1, j) << "\n";
        // cout << "\n";
    }
}

signed main () {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve ();
}