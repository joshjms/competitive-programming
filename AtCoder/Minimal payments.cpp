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

int n, x, arr[65];
pair<int,int> dp[65][2];

int binser(int cur, int unit, int cutoff, int state){
    if(!state){
        int l = -(1e18 / unit + 1), r = 1e18 / unit + 1, ret = 1e18 + 7;
        while(l <= r){
            int md = (l + r) / 2;
            if(cur + md * unit < cutoff - unit + 1)
                l = md + 1;
            else r = md - 1, ret = md;
        }
        return ret;
    }
    else{
        int l = -(1e18 / unit + 1), r = r = 1e18 / unit + 1, ret = -1e18 + 7;
        while(l <= r){
            int md = (l + r) / 2;
            if(cur + md * unit > cutoff + unit - 1)
                r = md - 1;
            else l = md + 1, ret = md;
        }
        return ret;
    }
    return 0;
}

pair <int,int> calc(int cur, int unit, int state, int val){
    if(state == 0){
        int k = binser(cur, unit, x, state);
        return {cur + k * unit, abs(k) + val};
    }
    else{
        int k = binser(cur, unit, x, state);
        return {cur + k * unit, abs(k) + val};
    }
}

pair<int,int> cmp(pair<int,int> p, pair<int,int> q){
    if(p.se < q.se) return p;
    return q;
}

void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j] = {0, 1e18 + 7};
        }
    }
    dp[n][0] = calc(0, arr[n], 0, 0);
    dp[n][1] = calc(0, arr[n], 1, 0);
    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j < 2; j++){
            dp[i][j] = cmp(dp[i][j], calc(dp[i + 1][0].fi, arr[i], j, dp[i + 1][0].se));
            dp[i][j] = cmp(dp[i][j], calc(dp[i + 1][1].fi, arr[i], j, dp[i + 1][1].se));
        }
    }
    cout << min(dp[1][0].se, dp[1][1].se) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}