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

int n, m, a[300005], b[300005], ans;
pair <int,int> c[300005];

pair<int,int> tree[1200005];
int lazy[1200005];

void reset(){
    for(int i = 0; i < 1200005; i++){
        tree[i] = {1e18 + 7, 1e18 + 7};
        lazy[i] = 0;
    }
}

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = {l - 1, l};
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

void push(int idx, int l, int r){
    if(lazy[idx] != 0){
        tree[idx].fi += lazy[idx];
        if(l != r){
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int x, int y, int v){
    push(idx, l, r);
    if(l > r || r < x || l > y) return;
    if(l >= x && r <= y){
        lazy[idx] += v;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(idx * 2, l, mid, x, y, v);
    upd(idx * 2 + 1, mid + 1, r, x, y, v);
    tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

pair <int,int> query(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return {1e18 + 7, 1e18 + 7};
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return min(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

vector <pair<int,int>> omgpeko, ohnopeko;

int bit[600005];

void add(int idx, int v){
    for(; idx <= n + m; idx += (idx & (-idx)))
        bit[idx] += v;
}

int sum(int idx){
    int res = 0;
    for(; idx > 0; idx -= (idx & (-idx)))
        res += bit[idx];
    return res;
}

int sum(int l, int r){
    if(l > r) return 0;
    return sum(r) - sum(l - 1);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[i].fi = a[i];
        c[i].se = i;
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    int akarin = 1, chinatsu = 1, nxt = 0;
    build(1, 1, n + 1);
    for(int i = 1; i <= m; i++){
        for(; akarin <= n && c[akarin].fi < b[i]; akarin++)
            upd(1, 1, n + 1, c[akarin].se + 1, n + 1, -1);
        for(; chinatsu <= n && c[chinatsu].fi <= b[i]; chinatsu++)
            upd(1, 1, n + 1, 1, c[chinatsu].se, 1);
        pair <int,int> peko = query(1, 1, n + 1, nxt, n + 1);
        nxt = peko.se;
        omgpeko.pb({peko.se - 1, b[i]});
    }
    sort(omgpeko.begin(), omgpeko.end(), greater<pair<int,int>>());
    for(int i = 1; i <= n + 1; i++){
        while(omgpeko.size() && omgpeko.back().fi < i){
            int sz = ohnopeko.size();
            ohnopeko.pb({omgpeko.back().se, sz + 1});
            omgpeko.pop_back();
        }
        if(i > n) continue;
        int sz = ohnopeko.size();
        ohnopeko.pb({a[i], sz + 1});
    }
    // for(auto i : ohnopeko)
    //     cout << i.fi << " ";
    // cout << "\n";
    memset(tree, 0, sizeof(tree));
    sort(ohnopeko.begin(), ohnopeko.end());
    for(auto i : ohnopeko){
        ans += sum(i.se, n + m);
        add(i.se, 1);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}