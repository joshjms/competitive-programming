#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, arr[200005], q;
vector <int> g[200005];

int tree[800005];
int lazy[800005];

void push(int idx, int l, int r){
    if(lazy[idx]) {
        tree[idx] = (r - l + 1) - tree[idx];
        if(l != r) {
            lazy[idx * 2] ^= 1;
            lazy[idx * 2 + 1] ^= 1;
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return;
    if(l >= x && r <= y) {
        lazy[idx] ^= 1;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(idx * 2, l, mid, x, y);
    upd(idx * 2 + 1, mid + 1, r, x, y);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int query(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, x, y) + query(idx * 2 + 1, mid + 1, r, x, y);
}

int tmr, in[200005], out[200005];

void dfs(int pos, int parent) {
    in[pos] = ++tmr;
    for(auto c : g[pos]) if(c != parent) {
        dfs(c, pos);
    }
    out[pos] = tmr;
}

void solve() {
    cin >> n;
    for(int i = 2, u; i <= n; i++){
        cin >> u;
        g[u].pb(i);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i]){
            upd(1, 1, n, in[i], in[i]);
        }
    }
    cin >> q;
    for(string type; q--;){
        cin >> type;
        if(type == "pow") {
            int v; cin >> v;
            upd(1, 1, n, in[v], out[v]);
        }
        if(type == "get") {
            int v; cin >> v;
            cout << query(1, 1, n, in[v], out[v]) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}