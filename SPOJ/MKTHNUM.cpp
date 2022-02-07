#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, q;
int pos[100005];
pair <int,int> arr[100005];

struct node{
    node *left, *right;
    int val = 0;
    node(int v){
        left = nullptr, right = nullptr, val = v;
    }
    node(node *lc, node *rc){
        left = lc;
        right = rc;
        if(lc != NULL) val += lc->val;
        if(rc != NULL) val += rc->val; 
    }
};

vector <node*> v;

struct segment_tree{
    node* build(int l, int r){
        if(l == r)
            return new node(0);
        int md = (l + r) / 2;
        return new node(build(l, md), build(md + 1, r));
    }
    node* upd(node* cur, int l, int r, int x, int v){
        if(l == r)
            return new node(v);
        int md = (l + r) / 2;
        if(x <= md) return new node(upd(cur->left, l, md, x, v), cur->right);
        else return new node(cur->left, upd(cur->right, md + 1, r, x, v));
    }
    int query(node* lnode, node* rnode, int l, int r, int k){
        if(l == r) return l;
        int md = (l + r) / 2;
        if(rnode->left->val - lnode->left->val >= k)
            return query(lnode->left, rnode->left, l, md, k);
        else return query(lnode->right, rnode->right, md + 1, r, k - (rnode->left->val - lnode->left->val));
    }
    int sum(node* cur, int l, int r, int x, int y){
        if(l > r || l > y || r < x) return 0;
        if(l >= x && r <= y) return cur->val;
        int md = (l + r) / 2;
        int ret = sum(cur->left, l, md, x, y) + sum(cur->right, md + 1, r, x, y);
        return ret;
    }
} segtree;

void solve(){
    cin >> n >> q;
    v.pb(segtree.build(1, n));
    for(int i = 1; i <= n; i++){
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++){
        pos[arr[i].se] = i;
    }
    for(int i = 1; i <= n; i++){
        v.pb(segtree.upd(v.back(), 1, n, pos[i], 1));
    }
    for(int t = 1, l, r, k; t <= q; t++){
        cin >> l >> r >> k;
        int p = segtree.query(v[l - 1], v[r], 1, n, k);
        cout << arr[p].fi << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}