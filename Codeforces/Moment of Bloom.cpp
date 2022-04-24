#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, q, o;
vector <int> g[300005];
vector <int> t[300005];

bool vis[300005];

int cnt[300005];
int par[300005][25], in[300005], out[300005], tmr;

void dfs(int pos) {
    vis[pos] = 1;
    for(int c : g[pos]) {
        if(!vis[c]) {
            t[pos].pb(c);
            dfs(c);
        }
    }
}

void dfslca(int pos) {
    in[pos] = ++tmr;
    for(int i = 1; i <= 20; i++) {
        par[pos][i] = par[par[pos][i - 1]][i - 1];
    }
    for(int c : t[pos]) if(c != par[pos][0]) {
        par[c][0] = pos;
        dfslca(c);
    }
    out[pos] = ++tmr;
}

bool parent(int u, int v) {
    if(u == 0) return true;
    if(in[u] < in[v] && out[u] > out[v]) return true;
    return false;
}

int lca(int u, int v) {
    if(parent(u, v)) return u;
    if(parent(v, u)) return v;
    for(int i = 20; i >= 0; i--) {
        if(parent(par[u][i], v) == false)
            u = par[u][i];
    }
    return par[u][0];
}

vector <int> ans[300005][2];

void solve () {
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    dfslca(1);
    cin >> q;
    for(int i = 1, u, v; i <= q; i++) {
        cin >> u >> v;
        cnt[u]++, cnt[v]++;
        int p = lca(u, v);
        for(; u != p; u = par[u][0]) ans[i][0].pb(u);
        ans[i][0].pb(p);
        for(; v != p; v = par[v][0]) ans[i][1].pb(v);
        reverse(ans[i][1].begin(), ans[i][1].end());
    }
    for(int i = 1; i <= n; i++)
        o += cnt[i] % 2;
    if(o) {
        cout << "NO\n" << o / 2 << "\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= q; i++) {
        cout << ans[i][0].size() + ans[i][1].size() << "\n";
        for(int j : ans[i][0]) cout << j << " ";
        for(int j : ans[i][1]) cout << j << " ";
        cout << "\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}