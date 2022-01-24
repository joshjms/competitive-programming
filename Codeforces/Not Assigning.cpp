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

int n, root;
vector <pair<int,int>> adj[100005];
int ans[100005];

void dfs(int node, int par, int parity){
    for(auto i : adj[node]) if(i.fi != par){
        ans[i.se] = (parity == 0 ? 2 : 5);
        dfs(i.fi, node, parity ^ 1);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        ans[i] = -1;
    }
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }  
    root = -1;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 2){
            cout << -1 << "\n";
            return;
        }
        if(adj[i].size() == 1){
            root = i;
        }
    }
    dfs(root, -1, 0);
    for(int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}