#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[300005];
int p[300005], q[300005], x;

int bit[300005];

struct rsqfwt {
    int bit[300005];
    void upd(int idx, int v) {
        for(; idx <= n; idx += idx & (-idx)) {
            (bit[idx] += v) %= mod;
        }
    }
    int sum(int idx) {
        int res = 0;
        for(; idx >= 1; idx -= idx & (-idx)) {
            (res += bit[idx]) %= mod;
        }
        return res;
    }
    int sum(int l, int r) {
        if(r < l) return 0;
        return (sum(r) - sum(l - 1) + mod) % mod;
    }
} sumbit;

struct rmqfwt {
    int bit[300005];
    void upd(int idx, int v) {
        for(; idx <= n; idx += idx & (-idx)) {
            bit[idx] = max(bit[idx], v);
        }
    }
    int maxi(int idx) {
        int res = 0;
        for(; idx >= 1; idx -= idx & (-idx)) {
            res = max(res, bit[idx]);
        }
        return res;
    }
} maxbit;

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    p[0] = 1, q[0] = 0;
    for(int i = 1; i <= n; i++) {
        x = maxbit.maxi(arr[i] - 1);
        maxbit.upd(arr[i], i);
        p[i] = (sumbit.sum(x, i - 1) + (x == 0 ? p[x] : 0)) % mod;
        (p[i] += q[x]) %= mod;
        q[i] = (p[x] + q[x] - (x == 0 ? 1 : 0)) % mod;
        sumbit.upd(i, p[i]);
    }
    // for(int i = 1; i <= n; i++)
    //     cout << p[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++)
    //     cout << q[i] << " ";
    // cout << "\n";
    cout << (p[n] + q[n]) % mod << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}