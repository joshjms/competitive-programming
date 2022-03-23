#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

const int N = 400000;
int q;

struct Line{
    ld m, b;
    ld operator()(ld x) {return m * x + b;}
} a[1600005];

void insert(int l, int r, Line seg, int o = 1){
    if(l == r){
        if(seg(l) > a[o](l)) a[o] = seg;
        return;
    }
    int mid = (l + r) / 2;
    int lson = o * 2;
    int rson = o * 2 + 1;
    if(a[o].m > seg.m) swap(a[o], seg);
    if(a[o](mid) < seg(mid)){
        swap(a[o], seg);
        insert(l, mid, seg, lson);
    }
    else insert(mid + 1, r, seg, rson);
}

ld query(int l, int r, int x, int o = 1){
    if(l == r) return a[o](x);
    int mid = (l + r) / 2;
    int lson = o * 2;
    int rson = o * 2 + 1;
    if(x < mid) return max(a[o](x), query(l, mid, x, lson));
    else return max(a[o](x), query(mid + 1, r, x, rson));
}

void solve(){
    cin >> q;
    for(ld a, b; q--;){
        string qry;
        cin >> qry;
        if(qry == "Project"){
            cin >> a >> b;
            insert(1, N, {b, a - b}, 1);
        }
        else{
            int x; cin >> x;
            ld f = query(1, N, x, 1);
            cout << f << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}