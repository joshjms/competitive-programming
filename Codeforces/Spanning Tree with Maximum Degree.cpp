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

int n, m;
pair <int,int> root;
vector <int> adj[200005];
queue <int> bfs;
bool vis[200005];
vector <pair<int,int>> ans;

void solve(){
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        root = max(root, {adj[i].size(), i});
    }
    bfs.push(root.se);
    vis[root.se] = 1;
    while(bfs.empty() == false){
        int pos = bfs.front();
        bfs.pop();

        for(auto i : adj[pos]) if(!vis[i]){
            ans.pb({pos, i});
            bfs.push(i);
            vis[i] = 1;
        }
    }
    for(auto i : ans)
        cout << i.fi << sp << i.se << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}