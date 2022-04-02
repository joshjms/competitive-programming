#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 998244353;

int n, q, arr[100005];
vector <int> g[100005];

int tree[400005];
int lazy[400005];

void push(int idx, int l, int r){
    if(lazy[idx]) {
        (tree[idx] += ((r - l + 1) * lazy[idx]) % mod) %= mod;
        if(l != r) {
            (lazy[idx * 2] += lazy[idx]) %= mod;
            (lazy[idx * 2 + 1] += lazy[idx]) %= mod;
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int x, int y, int v){
    push(idx, l, r);
    if(l > r || l > y || r < x) return;
    if(l >= x && r <= y) {
        (lazy[idx] += v) %= mod;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(idx * 2, l, mid, x, y, v);
    upd(idx * 2 + 1, mid + 1, r, x, y, v);
    tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % mod;
}

int query(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return (query(idx * 2, l, mid, x, y) + query(idx * 2 + 1, mid + 1, r, x, y)) % mod;
}

int parent[100005], pos[100005], in[100005], out[100005];
vector <int> order;

void bfs() {
    queue <pair<int,int>> q;
    q.push({1, -1});
    while(!q.empty()){
        int pos = q.front().fi;
        int par = q.front().se;
        parent[pos] = par;
        order.pb(pos);
        q.pop();
        for(auto c : g[pos]) if(c != par) {
            q.push({c, pos});
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs();
    for(int i = 0; i < order.size(); i++){
        pos[order[i]] = i + 1;
    }
    for(int i = 1; i <= n; i++){
        in[i] = 1e18 + 7;
        for(auto c : g[i]) if(c != parent[i]){
            in[i] = min(in[i], pos[c]);
            out[i] = max(out[i], pos[c]);
        }
    }
    for(int i = 1; i <= n; i++){
        upd(1, 1, n, pos[i], pos[i], arr[i]);
    }
    cin >> q;
    for(int t, u, v; q--;){
        cin >> t;
        if(t == 1){
            // update
            cin >> u;
            v = query(1, 1, n, pos[u], pos[u]);
            upd(1, 1, n, in[u], out[u], v);
            if(parent[u] != -1)
                upd(1, 1, n, pos[parent[u]], pos[parent[u]], v);
        }
        if(t == 2){
            // query
            cin >> u;
            if(parent[u] != -1)
                cout << (query(1, 1, n, in[u], out[u]) + query(1, 1, n, pos[parent[u]], pos[parent[u]])) % mod << "\n";
            else cout << query(1, 1, n, in[u], out[u]) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}