// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, q, arr[200005];

int par[200005];

void reset(){
    for(int i = 1; i <= n; i++)
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

struct node{
    int val;
    node * child[2];
    node(int idx){
        val = idx;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

node * root = new node(0);

void query(node * cur, int bit, int idx){
    if(bit < 0) {
        if((arr[idx] ^ arr[cur -> val]) <= m)
            join(idx, cur -> val);
        return;
    }
    int bit_m = (m >> bit) & 1ll;
    int bit_v = (arr[idx] >> bit) & 1ll;
    if(bit_m){
        // choosing v ^ x == 0
        int bit_x = bit_v ^ 0;
        if(cur -> child[bit_x])
            join(idx, cur -> child[bit_x] -> val);
    }
    int bit_x = bit_v ^ bit_m;
    if(cur -> child[bit_x])
        query(cur -> child[bit_x], bit - 1, idx);
}

void add(node * cur, int bit, int idx){
    if(bit < 0) return;
    int bit_v = (arr[idx] >> bit) & 1;
    if(!cur -> child[bit_v])
        cur -> child[bit_v] = new node(idx);
    add(cur -> child[bit_v], bit - 1, idx);
}

void solve(){
    cin >> n >> m >> q;
    reset();
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        query(root, 30, i);
        add(root, 30, i);
    }
    for(int u, v; q--;){
        cin >> u >> v;
        if(find(u) == find(v))
            cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}