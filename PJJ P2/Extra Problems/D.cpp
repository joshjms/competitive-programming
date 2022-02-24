// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, q;

struct node{
    int val;
    bool flip;
    vector <bool> book;
    node *left, *right;
    node(){
        val = 0;
        flip = 0;
        left = right = nullptr;
    }
};

node * roots[100005];

void build(node *cur, int l, int r){
    if(l == r){
        cur -> book.assign(m + 1, 0);
        return;
    }
    int md = (l + r) / 2;
    // left
    cur -> left = new node;
    build(cur -> left, l, md);
    // right
    cur -> right = new node;
    build(cur -> right, md + 1, r);
}

void setNode(node * u, node * v){
    u -> val = v -> val;
    u -> flip = v -> flip;
    for(int i = 0; i < v -> book.size(); i++)
        u -> book.push_back(v -> book[i]);
    u -> left = v -> left;
    u -> right = v -> right;
}

void add(node *cur, node *sub, int l, int r, int i, int j){
    setNode(cur, sub);
    if(l == r){
        if((cur -> book[j]) ^ (cur -> flip) == 0){
            cur -> val++;
            cur -> book[j] = 1 - cur -> book[j];
        }
        return;
    }
    int md = (l + r) / 2;
    if(i <= md){
        cur -> left = new node();
        add(cur -> left, sub -> left, l, md, i, j);
    }
    else{
        cur -> right = new node();
        add(cur -> right, sub -> right, md + 1, r, i, j);
    }
    cur -> val = cur -> left -> val + cur -> right -> val;
}

void del(node *cur, node * sub, int l, int r, int i, int j){
    setNode(cur, sub);
    if(l == r){
        if((cur -> book[j]) ^ (cur -> flip) == 1){
            cur -> val--;
            cur -> book[j] = 1 - cur -> book[j];
        }
        return;
    }
    int md = (l + r) / 2;
    if(i <= md){
        cur -> left = new node();
        del(cur -> left, sub -> left, l, md, i, j);
    }
    else{
        cur -> right = new node();
        del(cur -> right, sub -> right, md + 1, r, i, j);
    }
    cur -> val = cur -> left -> val + cur -> right -> val;
}

void flip(node *cur, node *sub, int l, int r, int i){
    setNode(cur, sub);
    if(l == r){
        cur -> flip ^= 1;
        cur -> val = m - cur -> val;
        return;
    }
    int md = (l + r) / 2;
    if(i <= md){
        cur -> left = new node();
        flip(cur -> left, sub -> left, l, md, i);
    }
    else{
        cur -> right = new node();
        flip(cur -> right, sub -> right, md + 1, r, i);
    }
    cur -> val = cur -> left -> val + cur -> right -> val;
}

void solve(){
    cin >> n >> m >> q;
    roots[0] = new node();
    build(roots[0], 1, n);
    for(int i = 1, t, u, v; i <= q; i++){
        roots[i] = new node();
        cin >> t;
        if(t == 1){
            cin >> u >> v;
            add(roots[i], roots[i - 1], 1, n, u, v);
        }
        if(t == 2){
            cin >> u >> v;
            del(roots[i], roots[i - 1], 1, n, u, v);
        }
        if(t == 3){
            cin >> u;
            flip(roots[i], roots[i - 1], 1, n, u);
        }
        if(t == 4){
            cin >> u;
            setNode(roots[i], roots[u]);
        }
        cout << roots[i] -> val << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}