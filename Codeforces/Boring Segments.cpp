#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, m, ans = 1e18 + 7;
pair <int,pair<int,int>> arr[300005];

int tree[4000005];
int lazy[4000005];

void push(int idx, int l, int r){
    if(lazy[idx]) {
        tree[idx] += lazy[idx];
        if(l != r) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int x, int y, int v){
    push(idx, l, r);
    if(l > r || l > y || r < x) return;
    if(l >= x && r <= y) {
        lazy[idx] += v;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(idx * 2, l, mid, x, y, v);
    upd(idx * 2 + 1, mid + 1, r, x, y, v);
    tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y){
    push(idx, l, r);
    if(l > r || l > y || r < x) return 1e18 + 7;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return min(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

int l, r;

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].se.fi >> arr[i].se.se >> arr[i].fi;
        arr[i].se.se --;
    }
    sort(arr + 1, arr + n + 1);
    for(l = 1, r = 0; l <= n; l++){
        while(r < l || (r <= n && query(1, 1, m - 1, 1, m - 1) <= 0)) { // minimum query
            r++;
            upd(1, 1, m - 1, arr[r].se.fi, arr[r].se.se, 1);
        }
        if(query(1, 1, m - 1, 1, m - 1) > 0)
            ans = min(ans, arr[r].fi - arr[l].fi);
        upd(1, 1, m - 1, arr[l].se.fi, arr[l].se.se, -1);
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}