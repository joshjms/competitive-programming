#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 998244353;

int n, e, q, r;
pair <int,int> edges[200005];
bool del[200005];

int par[50005], sz[50005], sp[50005];

int find(int u) {
    if(par[u] == u)
        return u;
    return par[u] = find(par[u]);
}

int join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return 0;
    par[u] = v, sz[v] += sz[u];
    return 1;
}

int ans;

void solve () {
    cin >> n >> e >> q >> r;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        sz[i] = 0, par[i] = i, sp[i] = 0;
    }
    for(int i = 1; i <= e; i++) {
        del[i] = 0;
    }
    for(int i = 1; i <= e; i++) {
        cin >> edges[i].fi >> edges[i].se;
    }
    for(int i = 1, node; i <= q; i++) {
        cin >> node;
        sp[node] = 1;
        sz[node] = 1;
    }
    for(int i = 1, edge; i <= r; i++) {
        cin >> edge;
        del[edge] = true;
    }
    for(int i = 1; i <= e; i++) if(del[i] == false) {
        join(edges[i].fi, edges[i].se);
    }
    for(int i = 1; i <= n; i++) {
        if(sp[i]) ans += q - sz[find(i)];
    }
    cout << ans / 2 << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) solve ();
}