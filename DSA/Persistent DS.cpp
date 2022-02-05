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

int n, arr[100005], q;

struct node{
    node *l, *r;
    int val;
    node(int v){
        l = nullptr, r = nullptr, val = v;
    }
    node(node lc, node rc){
        l = lc;
        r = rc;
        if(lc) val += lc->val;
        if(rc) val += rc->val; 
    }
};

vector <node*> v;

struct segment_tree{
    node* build(int l, int r){
        if(l == r){
            tree[idx].val = arr[l];
            return;
        }
        int md = (l + r) / 2;
        return new node(build(l, md), build(md + 1, r));
    }
    node* upd(node* cur, int l, int r, int x, int v){
        if(l == r)
            return new node(v);
        int md = (l + r) / 2;
        if(x <= md) return new node(upd(cur->l, l, md, x, v), cur->r);
        else return new node(cur->l, upd(cur->r, md + 1, r, x, v));
    }
    int query(node* cur, int l, int r, int x, int y){
        if(l > y || r < x || l > r) return 0;
        if(l >= x && r <= y) return cur->val;
        int md = (l + r) / 2;
        return query(cur->left, l, md, x, y) + query(cur->right, md + 1, r, x, y);
    }
} segtree;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    v.pb(build(1, n));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}