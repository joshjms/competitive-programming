#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, k;
vector <pair<int,int>> g[200005];
int l, r, mid, ans, cnt;
int e[200005];

void dfs(int pos, int par, int m) {
    int sz = g[pos].size();
    if(sz > m) cnt++;
    for(auto c : g[pos]) if(c.fi != par) dfs(c.fi, pos, m);
}

void backtrack(int pos, int par, int pc, int m) {
    int sz = g[pos].size(), idx = 1;
    if(sz > m) {
        for(auto c : g[pos]) if(c.fi != par) 
            e[c.se] = 1;
    }
    else {
        for(auto c : g[pos]) if(c.fi != par) {
            while(idx == pc) ++idx;
            e[c.se] = idx++;
        }
    }
    for(auto c : g[pos]) if(c.fi != par) backtrack(c.fi, pos, e[c.se], m);
}

void solve () {
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    l = 1, r = n - 1;
    while(l <= r) {
        mid = (l + r) / 2, cnt = 0;
        dfs(1, 0, mid);
        if(cnt <= k) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << "\n";
    backtrack(1, 0, 0, ans);
    for(int i = 1; i < n; i++)
        cout << e[i] << " ";
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}