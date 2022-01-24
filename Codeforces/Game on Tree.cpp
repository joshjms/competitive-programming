#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, d[100005];
vector <int> adj[100005];
ld ans;

void dfs(int pos, int par, int depth){
    d[pos] = depth;
    for(auto i : adj[pos]) if(i != par){
        dfs(i, pos, depth + 1);
    }
}

void solve(){
    cin >> n;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1, 1);
    for(int i = 1; i <= n; i++){
        ans += (ld) 1 / d[i];
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    solve();
}