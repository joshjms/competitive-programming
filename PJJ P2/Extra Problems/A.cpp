// AKARINNN!!!!!!!!! <3

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

int n, m, gr;
vector <int> g[1000005], rg[1000005];
bool vis[1000005];
int group[1000005];
vector <int> sccs[1000005];

void clearvis(){
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
}

void connect(int u, int v){
    if(u == v) return;
    g[u].pb(v);
    rg[v].pb(u);
}

vector <int> topo;

void toposort(int u){
    vis[u] = 1;
    for(auto i : g[u]) if(!vis[i])
        toposort(i);
    topo.pb(u);
}

void dfsscc(int u){
    vis[u] = 1;
    group[u] = gr;
    sccs[gr].pb(u);
    for(auto i : rg[u]) if(!vis[i])
        dfsscc(i);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        rg[i].clear();
        sccs[i].clear();
    }
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        connect(u, v);
    }
    clearvis();
    topo.clear();
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            toposort(i);
    }
    reverse(topo.begin(), topo.end());
    clearvis();
    gr = 0;
    for(auto i : topo){
        if(!vis[i]){
            ++gr;
            dfsscc(i);
        }
    }
    if(gr == 1){
        cout << "No\n";
        return;
    }
    for(int i = 1; i <= gr; i++){
        bool flag = 1;
        for(auto u : sccs[i]){
            for(auto v : g[u]){
                if(group[u] != group[v])
                    flag = 0;
            }
        }
        if(flag){
            cout << "Yes\n";
            cout << sccs[i].size() << " " << n - sccs[i].size() << "\n";
            for(auto u : sccs[i])
                cout << u << " ";
            cout << "\n";
            for(int j = 1; j <= n; j++)
                if(group[j] != i)
                    cout << j << " ";
            cout << "\n";
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}