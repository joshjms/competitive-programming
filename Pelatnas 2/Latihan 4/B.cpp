// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, arr [200005], ans;
vector <int> g [200005];
vector <pair<int,int>> nodes;

int par[200005], val[200005];

int find(int u){
    if(u == par[u])
        return u;
    return par[u] = find(par[u]);
}

int join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    par[u] = v;
    ans += val[v] + val[u];
    val[v] = max(val[v], val[u]);
    return 1;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        nodes.pb({arr[i], i});
    }
    for(int i = 1; i <= n; i++){
        par[i] = i;
        val[i] = arr[i];
    }
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    sort(nodes.begin(), nodes.end());
    for(auto i : nodes){
        int u = find(i.se);
        for(auto j : g[i.se]){
            int v = find(j);
            if(val[u] >= val[v])
                join(u, v);
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}