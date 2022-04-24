#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, q, arr[100005];

int segment_tree[400005];

void build(int idx, int l, int r) {
    if(l == r) {
        segment_tree[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    int left_child = idx * 2;
    int right_child = idx * 2 + 1;
    build(left_child, l, mid);
    build(right_child, mid + 1, r);
    segment_tree[idx] = segment_tree[idx * 2] + segment_tree[idx * 2 + 1];
}

void upd(int idx, int l, int r, int u, int v) {
    if(l == r) {
        segment_tree[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    int left_child = idx * 2;
    int right_child = idx * 2 + 1;
    if(u <= mid) upd(left_child, l, mid, u, v);
    else upd(right_child, mid + 1, r, u, v);
    segment_tree[idx] = segment_tree[idx * 2] + segment_tree[idx * 2 + 1];
}

int query(int idx, int l, int r, int x, int y) {
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return segment_tree[idx];
    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, x, y) + query(idx * 2 + 1, mid + 1, r, x, y);
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    for(int t = 1, qry; t <= q; t++) {
        // query 1 - update: ganti A[u] = v
        // 1 u v
        // query 2 - sum : find sum from A[x] to A[y]
        // 2 x y
        cin >> qry;
        if(qry == 1) {
            int u, v;
            cin >> u >> v;
            upd(1, 1, n, u, v);
        }
        else if(qry == 2) {
            // sum
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}