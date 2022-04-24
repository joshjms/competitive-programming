#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 998244353;

int n, m;
map <string,int> mp;
int node;

vector <int> g[10005];

string a, b, sp[10005];

bool vis[10005];
vector <int> ans;

bool dfs(int pos, int dest) {
    if(pos == dest) { ans.pb(pos); return 1; }
    vis[pos] = true;
    for(auto c : g[pos]) if(!vis[c]) {
        bool b = dfs(c, dest);
        if(b) { ans.pb(pos); return 1; }
    }
    return 0;
}

void solve () {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        string parent, child;
        cin >> parent >> child;
        if(mp[parent] == 0) mp[parent] = ++node, sp[node] = parent;
        if(mp[child] == 0) mp[child] = ++node, sp[node] = child;
        g[mp[parent]].pb(mp[child]);
    }
    cin >> a >> b;
    for(int i = 1; i <= n; i++) vis[i] = false;
    if(dfs(mp[a], mp[b])) {
        reverse(ans.begin(), ans.end());
        for(auto i : ans) 
            cout << sp[i] << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) vis[i] = false;
    if(dfs(mp[b], mp[a])) {
        reverse(ans.begin(), ans.end());
        for(auto i : ans) 
            cout << sp[i] << "\n";
        return;
    }
    cout << "TIDAK MUNGKIN\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}