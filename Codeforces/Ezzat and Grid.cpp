#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, m, s;
pair <int,int> tree[2400005], lazy[2400005];
pair <int,int> dp[300005];
int bt[300005];
vector <pair<int,int>> seg[300005];
vector <int> comp;
pair <int,int> maxi;
set <int> st;

void push(int idx, int l, int r) {
    if(lazy[idx] != make_pair(0, 0)) {
        tree[idx] = max(tree[idx], lazy[idx]);
        if(l != r) {
            lazy[idx * 2] = max(lazy[idx], lazy[idx * 2]);
            lazy[idx * 2 + 1] = max(lazy[idx], lazy[idx * 2 + 1]);
        }
        lazy[idx] = {0, 0};
    }
}

void upd(int idx, int l, int r, int x, int y, pair <int,int> v) {
    push(idx, l, r);
    if(l > r || l > y || r < x) return;
    if(l >= x && r <= y) {
        lazy[idx] = max(lazy[idx], v);
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(idx * 2, l, mid, x, y, v);
    upd(idx * 2 + 1, mid + 1, r, x, y, v);
    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

pair <int,int> query(int idx, int l, int r, int x, int y) {
    push(idx, l, r);
    if(l > r || l > y || r < x) return {0, 0};
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

void solve() {
    cin >> n >> m;
    for(int i = 1, u, l, r; i <= m; i++){
        cin >> u >> l >> r;
        seg[u].pb({l, r});
        comp.push_back(l);
        comp.push_back(r);
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    for(int i = 1; i <= n; i++){
        for(auto &j : seg[i]) {
            j.fi = lower_bound(comp.begin(), comp.end(), j.fi) - comp.begin() + 1;
            j.se = lower_bound(comp.begin(), comp.end(), j.se) - comp.begin() + 1;
        }
    }
    s = comp.size();
    for(int i = 1; i <= n; i++) {
        for(auto j : seg[i]) {
            pair <int,int> p = query(1, 1, s, j.fi, j.se);
            dp[i] = max(dp[i], p);
        }
        dp[i].fi++;
        bt[i] = dp[i].se;
        for(auto j : seg[i]) {
            upd(1, 1, s, j.fi, j.se, {dp[i].fi, i});
        }
        maxi = max(maxi, {dp[i].fi, i});
    }
    cout << n - maxi.fi << "\n";
    while(maxi.se != 0) {
        st.insert(maxi.se);
        maxi.se = bt[maxi.se];
    }
    for(int i = 1; i <= n; i++) {
        if(!st.count(i)){
            cout << i << " ";
        }
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}