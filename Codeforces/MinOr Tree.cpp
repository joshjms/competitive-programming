#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;

int tc;

int n, m, ans;
vector <pair<int,int>> adj[200005];
vector <int> banned;
bool vis[200005];

int dfs(int pos){
    int res = 1;
    vis[pos] = 1;
    for(auto i : adj[pos]) if(vis[i.fi] == 0){
        bool ok = 1;
        for(auto j : banned){
            if(i.se & (1ll << j)){
                ok = 0;
                break;
            }
        }
        if(ok) res += dfs(i.fi);
    }
    return res;
}

void solve(){
    banned.clear();
    ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        adj[i].clear();
    for(int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
for(int p = 30; p >= 0; p--){
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    banned.push_back(p);
    int nodes = dfs(1); // is it possible to create
    if(nodes == n);
    else{
        ans += (1ll << p);
        banned.pop_back();
    }
}
    cout << ans << "\n";
}

signed main(){
    cin >> tc;
    while(tc--)
        solve();
} 