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

int n, ans = 0;
pair <int,int> arr[200005];
vector <int> vect[200005];
int sz[200005];

int tree[1200005];
int lazy[1200005];

void push(int idx, int l, int r){
    if(lazy[idx] != 0){
        tree[idx] += lazy[idx];
        if(l != r){
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void upd(int idx, int l, int r, int x, int y, int v){
    push(idx, l, r);
    if(l > r || r < x || l > y) return;
    if(l >= x && r <= y){
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

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].fi >> arr[i].se;
        ans += arr[i].se;
        swap(arr[i].fi, arr[i].se);
    }
    sort(arr + 1, arr + n + 1, greater<pair<int,int>>());
    for(int i = 1; i <= n + 1; i++)
        upd(1, 1, n + 1, i, i, n - i);
    for(int i = 1; i <= n; i++){
        int q = query(1, 1, n + 1, 1, arr[i].se);
        if(q > 0){
            ans -= arr[i].fi;
            upd(1, 1, n + 1, 1, arr[i].se, -1);
        }
    }
    cout << ans << "\n";
}  

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

/*
5
1 2
1 2
1 2
4 1
3 0
*/