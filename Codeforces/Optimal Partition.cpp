#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[500005];
pair <int,int> p[500005];
int ord[500005], qord[500005];

int bit[500005];
int dp[500005];

void upd(int idx, int v) {
    for(; idx <= n; idx += (idx & (-idx)))
        bit[idx] = max(bit[idx], v);
}

int query(int idx) {
    int ret = -1e18 - 7;
    for(; idx >= 1; idx -= (idx & (-idx))) {
        ret = max(ret, bit[idx]);
    }
    return ret;
}

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        p[i].fi = p[i - 1].fi + arr[i];
        p[i].se = i;

        bit[i] = -1e18;
        dp[i] = -1e18;
    }
    sort(p + 1, p + n + 1);
    for(int i = 1; i <= n; i++) {
        ord[p[i].se] = i;
        if(i > 1 && p[i].fi == p[i - 1].fi) qord[p[i].se] = qord[p[i - 1].se];
        else qord[p[i].se] = i;
    }
    for(int i = 1, sum = 0; i <= n; i++) {
        sum += arr[i];
        dp[i] = dp[i - 1] + (arr[i] == 0 ? 0 : abs(arr[i]) / arr[i]);
        dp[i] = max(dp[i], query(qord[i] - 1) + i);
        if(sum > 0) dp[i] = i;
        upd(ord[i], dp[i] - i);
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    cout << dp[n] << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while(tc--) solve();
}