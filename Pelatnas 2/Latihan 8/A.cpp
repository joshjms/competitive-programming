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

int n, q, arr[4000005], ne[4000005], la[4000005], be[4000005], len[4000005];
int bk[4000005];

int tree[8000005];
int lazy[8000005];

void upd(int idx, int l, int r, int x, int v){
    if(l == r){
        tree[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) upd(idx * 2, l, mid, x, v);
    else upd(idx * 2 + 1, mid + 1, r, x, v);
    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int idx, int l, int r, int x, int y){
    if(l > r || l > y || r < x) return 0;
    if(l >= x && r <= y) return tree[idx];
    int mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, x, y), query(idx * 2 + 1, mid + 1, r, x, y));
}

int mt[8000005];

void upd2(int idx, int l, int r, int x, int v){
    if(l == r){
        mt[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    if(x <= mid) upd2(idx * 2, l, mid, x, v);
    else upd2(idx * 2 + 1, mid + 1, r, x, v);
    mt[idx] = min(mt[idx * 2], mt[idx * 2 + 1]);
}

int qry2(int idx, int l, int r, int x, int y){
    if(l > r || l > y || r < x) return 1e18 + 7;
    if(l >= x && r <= y) return mt[idx];
    int mid = (l + r) / 2;
    return min(qry2(idx * 2, l, mid, x, y), qry2(idx * 2 + 1, mid + 1, r, x, y));
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(bk[arr[i]]){
            ne[bk[arr[i]]] = i;
        }
        bk[arr[i]] = i;
        ne[i] = 1e18 + 7;
    }
    for(int i = 1; i <= n; i++)
        upd2(1, 1, n, i, ne[i]);
    for(int i = 1; i <= n; i++){
        be[i] = 1e18 + 7;
    }
    int L = 1, R = 1;
    for(; R <= n; R++){
        while(L <= R && qry2(1, 1, n, L, R + 1) <= R + 1){
            la[L] = R;
            L++;
        }
    }
    for(int i = 1; i <= n; i++)
        if(la[i] == 0) la[i] = n;
    for(int i = 1; i <= n; i++){
        be[la[i]] = min(be[la[i]], i);
    }
    for(int i = n; i >= 1; i--){
        if(be[i] > n){
            be[i] = be[i + 1];
        }
    }
    for(int i = 1; i <= n; i++)
        if(la[i] == 0)
            la[i] = n;
    for(int i = 1; i <= n; i++)
        len[i] = la[i] - i + 1;
    // for(int i = 1; i <= n; i++)
    //     cout << la[i] << " ";
    // cout << "\n";
    for(int i = 1; i <= n; i++){
        upd(1, 1, n, i, len[i]);
    }
    int prv = 0ll;
    for(int p, r; q--;){
        cin >> p >> r;
        p ^= prv, r ^= prv;
        prv = query(1, 1, n, be[r], p);
        cout << prv << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}