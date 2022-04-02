#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int N = 1e5, Q;
int A[N + 5];

int tree[4 * N + 5];
int lazy[4 * N + 5];

void propagate(int idx, int cur_l, int cur_r){
    if(lazy[idx] != 0) {
        tree[idx] += (cur_r - cur_l + 1) * lazy[idx];
        // if all elements in the segment gets added by X
        // then the sum of all elements in the segment increases by 
        // X * the number of elements (R - L + 1)
        if(cur_l != cur_r) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int cur_l, int cur_r, int l, int r, int v){
    propagate(idx, cur_l, cur_r);
    if(cur_l > cur_r || cur_l > r || cur_r < l) return;
    if(cur_l >= l && cur_r <= r){
        lazy[idx] += v;
        propagate(idx, cur_l, cur_r);
        return;
    }
    int mid = (cur_l + cur_r) / 2;
    int lchild = idx * 2;
    int rchild = idx * 2 + 1;
    upd(lchild, cur_l, mid, l, r, v);
    upd(rchild, mid + 1, cur_r, l, r, v);
    tree[idx] = tree[lchild] + tree[rchild];
}

int query(int idx, int cur_l, int cur_r, int l, int r){
    propagate(idx, cur_l, cur_r);
    if(cur_l > cur_r || cur_l > r || cur_r < l) return 0;
    if(cur_l >= l && cur_r <= r) return tree[idx];
    int mid = (cur_l + cur_r) / 2;
    int lchild = idx * 2;
    int rchild = idx * 2 + 1;
    return query(lchild, cur_l, mid, l, r) + query(rchild, mid + 1, cur_r, l, r);
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> Q;
    for(string T; Q--;) {
        cin >> T;
        if(T == "UPDATE") {
            // add A[i] by X for all L <= i <= R
            int L, R, X;
            cin >> L >> R >> X;
            upd(1, 1, N, L, R, X); 
        }
        if(T == "QUERY") {
            // query sum of A[i] where L <= i <= R
            int L, R;
            cin >> L >> R;
            cout << query(1, 1, N, L, R) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}