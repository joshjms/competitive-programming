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

int n, arr[100005];

struct fenwick_tree{
    int bit[100005];
    int sum(int idx){
        int sum = 0;
        for(; idx >= 1; idx -= (idx & -idx))
            sum += bit[idx];
        return sum;
    }
    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
    int upd(int idx, int val){
        for(; idx <= n; idx += (idx & -idx))
            bit[idx] += val;
    }
} fwt;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        fwt.upd(i, arr[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}