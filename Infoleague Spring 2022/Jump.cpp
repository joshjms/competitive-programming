#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, q, x [600005], y [600005];
vector <int> vx;

struct query {
    char t;
    int x1, y1, x2, y2;
};
query qry[600005];

set <int> st [600005];
int mx;

ll tree[2400005];

void build() {
    for(int i = 1; i <= 2400000; i++)
        tree[i] = 1;
}

void upd(int idx, int l, int r, int x, int v) {
    if(l == r) {
        tree[idx] += v;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) upd(idx * 2, l, mid, x, v);
    else upd(idx * 2 + 1, mid + 1, r, x, v);
    tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % mod;
}

ll query(int idx, int l, int r, int x, int y) {
    if(l > r || l > y || r < x) return 1;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return (query(idx * 2, l, mid, x, y) * query(idx * 2 + 1, mid + 1, r, x, y)) % mod;
}

void solve (){
    cin >> n >> q;
    build();
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        vx.pb(x[i]);
    }
    for(int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    for(int i = 1; i <= q; i++) {
        cin >> qry[i].t;
        if(qry[i].t == '!') {
            cin >> qry[i].x1 >> qry[i].y1;
            vx.pb(qry[i].x1);
        }
        else {
            cin >> qry[i].x1 >> qry[i].y1 >> qry[i].x2 >> qry[i].y2;
        }
    }
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    sort(vx.begin(), vx.end());
    mx = vx.size();
    for(int i = 1; i <= n; i++)
        x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
    for(int i = 1; i <= q; i++) {
        qry[i].x1 = lower_bound(vx.begin(), vx.end(), qry[i].x1) - vx.begin() + 1;
        if(qry[i].t == '?') qry[i].x2 = lower_bound(vx.begin(), vx.end(), qry[i].x2) - vx.begin() + 1;
    }
    for(int i = 1; i <= n; i++) {
        int idx = x[i];
        upd(1, 1, mx, idx, 1);
        st[idx].insert(y[i]);
    }
    for(int i = 1; i <= q; i++) {
        if(qry[i].t == '!') {
            int idx = qry[i].x1;
            if(!st[idx].count(qry[i].y1)){
                upd(1, 1, mx, idx, 1);
                st[idx].insert(qry[i].y1);
            }
            else{
                upd(1, 1, mx, idx, -1);
                st[idx].erase(qry[i].y1);
            }
        }
        else if(qry[i].t == '?') {
            if(qry[i].x1 == qry[i].x2 && qry[i].y1 == qry[i].y2) {
                cout << 1 << "\n";
                continue;
            }
            int l = qry[i].x1;
            int r = qry[i].x2;
            if(l >= r) cout << 0 << "\n";
            else {
                ll res = query(1, 1, mx, l + 1, r - 1);
                cout << res << "\n";
            }
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}