#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int n, m, arr[1000005], cnt[1000005];

struct segment_tree{
    int tree[4000005][21];
    int lazy[4000005];

    void reset(){
        for(int i = 0; i <= 4 * n; i++){
            lazy[i] = 0;
            for(int j = 0; j <= 20; j++)
                tree[i][j] = 1e9 + 7;
        }
    }

    void build(int idx, int l, int r){
        if(l == r){
            tree[idx][cnt[l]] = l;
            return;
        }
        int md = (l + r) / 2;
        build(idx * 2, l, md);
        build(idx * 2 + 1, md + 1, r);
        for(int j = 0; j <= 20; j++){
            tree[idx][j] = min(tree[idx * 2][j], tree[idx * 2 + 1][j]);
        }
    }

    void push(int idx, int l, int r){
        if(lazy[idx] == 1){
            lazy[idx] = 0;
            for(int i = 0; i <= 10; i++)
                swap(tree[idx][i], tree[idx][20 - i]);
            if(l < r){
                lazy[idx * 2] ^= 1;
                lazy[idx * 2 + 1] ^= 1;
            }
        }
    }

    void upd(int idx, int l, int r, int x, int y){
        push(idx, l, r);
        if(l > r || l > y || r < x) return;
        if(l >= x && r <= y){
            lazy[idx] ^= 1;
            push(idx, l, r);
            return;
        }
        int md = (l + r) / 2;
        upd(idx * 2, l, md, x, y);
        upd(idx * 2 + 1, md + 1, r, x, y);
        for(int j = 0; j <= 20; j++){
            tree[idx][j] = min(tree[idx * 2][j], tree[idx * 2 + 1][j]);
        }
    }

    int query(int idx, int l, int r, int x, int y, int p){
        push(idx, l, r);
        if(l > r || l > y || r < x) return 1e9 + 7;
        if(l >= x && r <= y) return tree[idx][p];
        int md = (l + r) / 2;
        return min(query(idx * 2, l, md, x, y, p), query(idx * 2 + 1, md + 1, r, x, y, p));
    }
} segtree;

void newTestCase(){
    memset(cnt, 0, sizeof(cnt));
    segtree.reset();
}

void solve(){
    cin >> n >> m;
    newTestCase();
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        for(int j = 0; j <= 20; j++){
            if(arr[i] & (1ll << j)){
                cnt[i]++;
            }
        }
    }
    segtree.build(1, 1, n);
    for(int i = 1, t, l, r, v; i <= m; i++){
        cin >> t >> l >> r;
        if(t == 1){
            cin >> v;
            int parity = 0, ans = 1e9 + 7;
            while(v){
                if(v & 1) parity++;
                v >>= 1;
            }
            for(int d = 0; d <= 20 && ans == 1e9 + 7; d++){
                int okita = 1e9 + 7;
                if(parity + d <= 20) okita = segtree.query(1, 1, n, l, r, parity + d);
                int nobbu = 1e9 + 7;
                if(parity - d >= 0) nobbu = segtree.query(1, 1, n, l, r, parity - d);
                ans = min(okita, nobbu);
            }
            cout << ans << "\n";
        }
        else if(t == 2){
            segtree.upd(1, 1, n, l, r);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++){
        cout << "Case " << ntc << ":\n";
        solve();
    }
}