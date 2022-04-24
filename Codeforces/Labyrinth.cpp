#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, s, t;
vector <int> g[200005];
bool vis[200005], vis2[200005];

int par[200005];
bool ans = false;
vector <int> v[2];

void dfs(int pos) {
    vis[pos] = true;
    for(auto c : g[pos]) {
        if(c == s) continue;
        if(vis2[c] == true) {
            v[1].pb(c);
            v[1].pb(pos);
            t = c;
            ans = true;
            return;
        }
        if(!vis[c]) {
            par[c] = pos;
            dfs(c);
            if(ans == true) {
                v[1].pb(pos);
                return;
            }
        }
    }
}

void dfs2(int pos) {
    vis2[pos] = true;
    for(auto c : g[pos]) {
        if(c == s) continue;
        if(!vis2[c]) {
            dfs2(c);
        }
    }
}

void solve () {
    cin >> n >> m >> s;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].pb(v);
    }
    vis[s] = true;
    for(int c : g[s]) {
        if (vis2[c] == true) {
            t = c;
            v[1].pb(c);
            ans = true;
            break;
        }
        par[c] = s;
        dfs(c);
        if(ans == true) break;
        dfs2(c);
    }
    if(ans == true) {
        cout << "Possible\n";
        v[1].pb(s);
        reverse(v[1].begin(), v[1].end());
        while(t) {
            v[0].pb(t);
            t = par[t];
        }
        reverse(v[0].begin(), v[0].end());
        cout << v[0].size() << "\n";
        for(auto i : v[0])
            cout << i << " ";
        cout << "\n";
        cout << v[1].size() << "\n";
        for(auto i : v[1])
            cout << i << " ";
        cout << "\n";
    }
    else {
        cout << "Impossible\n";
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}