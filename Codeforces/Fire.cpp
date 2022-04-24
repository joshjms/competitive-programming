#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, dp[105][2005];
pair<pair <int,int>, int> bt[105][2005];

pair <int,pair<int,int>> ans;
vector <int> take;

struct item {
    int t, d, p, idx;
} arr[105];

bool cmp(item a, item b) {
    return a.d < b.d;
}

void solve () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].t >> arr[i].d >> arr[i].p;
        arr[i].idx = i;
    }
    sort(arr + 1, arr + n + 1, cmp);
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 2000; j++) {
            if(dp[i][j] == -1) continue;
            if(dp[i + 1][j] < dp[i][j]){
                dp[i + 1][j] = dp[i][j];
                bt[i + 1][j] = {{i, j}, 0};
            }
            if(j + arr[i].t < arr[i].d) {
                if(dp[i + 1][j + arr[i].t] < dp[i][j] + arr[i].p) {
                    dp[i + 1][j + arr[i].t] = dp[i][j] + arr[i].p;
                    bt[i + 1][j + arr[i].t] = {{i, j}, 1};
                }
            }
        }
    }
    // for(int i = 1; i <= n + 1; i++) {
    //     for(int j = 0; j <= 10; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i <= 2000; i++)
        ans = max(ans, {dp[n + 1][i], {n + 1, i}});
    pair <int,int> p = ans.se;
    while(p != make_pair(1ll, 0ll)) {
        if(bt[p.fi][p.se].se) take.pb(arr[p.fi - 1].idx);
        p = bt[p.fi][p.se].fi;
    }
    cout << ans.fi << "\n";
    cout << take.size() << "\n";
    reverse(take.begin(), take.end());
    for(auto i : take) cout << i << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}