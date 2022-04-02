#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, ans;
vector <int> g[300005];
pair <int,int> dp[300005], dp2[300005];
vector <int> cdp[300005], cdp2[300005];

void dfs(int pos, int par) {
    int diameter = 0;
    cdp[pos].pb(0);
    cdp[pos].pb(0);
    cdp2[pos].pb(0);
    cdp2[pos].pb(0);
    for(auto c : g[pos]) if(c != par) {
        dfs(c, pos);
        cdp[pos].pb(dp[c].fi + 1);
        cdp2[pos].pb(dp[c].se);
        dp[pos].fi = max(dp[pos].fi, dp[c].fi + 1);
        dp[pos].se = max(dp[pos].se, dp[c].se);
    }
    sort(cdp[pos].begin(), cdp[pos].end());
    sort(cdp2[pos].begin(), cdp2[pos].end());
    diameter += cdp[pos][cdp[pos].size() - 1] + cdp[pos][cdp[pos].size() - 2];
    dp[pos].se = max(dp[pos].se, diameter);
}

void reroot(int pos, int par) {
    if(pos != 1) {
        int res = dp[pos].se;
        int max_diameter = 0, max_depth = 0;
        if(cdp[par][cdp[par].size() - 1] == dp[pos].fi + 1) 
            max_diameter = cdp[par][cdp2[par].size() - 2] + cdp[par][cdp[par].size() - 3];
        else if(cdp[par][cdp[par].size() - 2] == dp[pos].fi + 1)
            max_diameter = cdp[par][cdp[par].size() - 1] + cdp[par][cdp[par].size() - 3];
        else max_diameter = cdp[par][cdp[par].size() - 1] + cdp[par][cdp[par].size() - 2];
        if(cdp2[par][cdp2[par].size() - 1] == dp[pos].se)
            max_diameter = max(max_diameter, cdp2[par][cdp2[par].size() - 2]);
        else max_diameter = max(max_diameter, cdp2[par][cdp2[par].size() - 1]);
        if(cdp[par][cdp[par].size() - 1] == dp[pos].fi + 1)
            max_depth = max(max_depth, cdp[par][cdp[par].size() - 2]);
        else max_depth = max(max_depth, cdp[par][cdp[par].size() - 1]);
        // debug(pos);
        // debug(res);
        // debug(max_diameter);
        // debug(max_depth);
        // cout << "\n";
        ans = max(ans, res + max_diameter + 1);
        cdp[pos].pb(max_depth + 1);
        cdp2[pos].pb(max_diameter);
    }
    sort(cdp[pos].begin(), cdp[pos].end());
    sort(cdp2[pos].begin(), cdp2[pos].end());
    for(auto c : g[pos]) if(c != par) {
        reroot(c, pos);
    }
}

void solve (){
    cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    reroot(1, -1);
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}