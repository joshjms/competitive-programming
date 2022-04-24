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

vector <int> g[50005];
bool sp[50005];

bool vis[200005];
int specialNodesInThisConnectedComponent;

void dfs(int pos) {
    vis[pos] = true;
    if(sp[pos] == true) specialNodesInThisConnectedComponent++;
    for(auto c : g[pos]) if(vis[c] == false) {
        dfs(c);
    }
}

int ans;

void solve () {
    cin >> n >> e >> q >> r;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
        g[i].clear();
        sp[i] = 0;
    }
    for(int i = 1; i <= e; i++) {
        del[i] = 0;
    }
    for(int i = 1; i <= e; i++) {
        cin >> edges[i].fi >> edges[i].se;
    }
    for(int i = 1, node; i <= q; i++) {
        cin >> node;
        sp[node] = true;
    }
    for(int i = 1, edge; i <= r; i++) {
        cin >> edge;
        del[edge] = true;
    }
    for(int i = 1; i <= e; i++) if(del[i] == false) {
        g[edges[i].fi].pb(edges[i].se);
        g[edges[i].se].pb(edges[i].fi);
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            specialNodesInThisConnectedComponent = 0;
            dfs(i);
            ans += specialNodesInThisConnectedComponent * (q - specialNodesInThisConnectedComponent);
        }
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