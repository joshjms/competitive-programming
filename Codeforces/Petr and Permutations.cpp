#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n;
pair <int,int> arr[1000005];

int inversion;

int bit[1000005];

int sum(int idx) {
    int res = 0;
    for(; idx >= 1; idx -= (idx & (-idx)))
        res += bit[idx];
    return res;
}

int sum(int l, int r){
    return sum(r) - sum(l - 1);
}

void upd(int idx, int v) {
    for(; idx <= n; idx += (idx & (-idx)))
        bit[idx] += v;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++){
        inversion += sum(arr[i].se);
        upd(arr[i].se, 1);
    }
    if(inversion % 2 == (3 * n) % 2)
        cout << "Petr\n";
    else cout << "Um_nik\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}