// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int q;

set <int> st;
map <int,int> idx;
int tmr;

struct query{
    int t, l, r, w;
};

vector <query> v;

int tree[1600005];

int merge(int a, int b){
    if(a == -1 || b == -1) return -1;
    return a ^ b;
}

void upd(int idx, int l, int r, int x, int v){
    if(l == r){
        if(tree[idx] == -1)
            tree[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) upd(idx * 2, l, mid, x, v);
    else upd(idx * 2 + 1, mid + 1, r, x, v);
    tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y){
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return merge(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

void solve(){
    cin >> q;
    memset(tree, -1, sizeof(tree));
    for(int t, l, r, w; q--;){
        cin >> t;
        if(t == 1){
            cin >> l >> r >> w;
            st.insert(l);
            st.insert(r);
            v.pb({1, l, r, w});
        }
        else{
            cin >> l >> r;
            st.insert(l);
            st.insert(r);
            v.pb({2, l, r, -1});
        }
    }
    for(auto i : st)
        idx[i] = ++tmr;
    for(int i = 0; i < v.size(); i++){
        v[i].l = idx[v[i].l];
        v[i].r = idx[v[i].r];
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i].t == 1){
            upd(1, 1, tmr, v[i].l, v[i].w);
        }
        else{
            cout << query(1, 1, tmr, v[i].l, v[i].r) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}