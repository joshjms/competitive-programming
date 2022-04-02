#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, arr[100005], parent[100005], ans;
vector <int> g[100005];
int dp[100005];
bool vis[100005];

void dfs(int pos, int par) {
    vis[pos] = true;
    pair <int,int> p = {1e18, 1e18};
    for(int c : g[pos]) if(c != par) {
        dfs(c, pos);
        p = min(p, {dp[c], c});
    }
    for(int c : g[pos]) if(c != par) {
        if(c != p.se) ans += dp[c];
    }
    if(p.fi > 1e9) p.fi = -1;
    dp[pos] = max(p.fi, arr[pos]);
}

void solve () {
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        g[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> parent[i];
        g[parent[i]].pb(i);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        dfs(i, -1);
        ans += dp[i];
    }
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    for(int ntc = 1; ntc <= tc; ntc++) {
        cout << "Case #" << ntc << ": ";
        solve ();
    }
}