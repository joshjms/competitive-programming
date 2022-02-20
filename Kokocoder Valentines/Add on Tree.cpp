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

int n, m[1005][1005], u[1005], v[1005];
vector <int> g[1005];
int akari;
vector <pair<pair<int,int>,int>> ans;
int par[1005];

void dfs1(int pos){
    for(auto i : g[pos]) if(i != par[pos]){
        par[i] = pos;
        dfs1(i);
    }
}

int dfsleaf(int pos){
    if(g[pos].size() == 1) return pos;
    int it = 0, leaf = akari;
    for(; g[pos][it] == par[pos]; it++);
    leaf = dfsleaf(g[pos][it]);
    return leaf;
}

void dfs2(int pos){
    for(auto i : g[pos]) if(i != par[pos]){
        dfs2(i);
    }
    if(pos == akari) return;
    // path from akari to pos
    if(g[pos].size() == 1){
        int c = m[pos][par[pos]];
        ans.pb({{akari, pos}, c});
        for(int node = pos; node != akari; node = par[node]){
            m[node][par[node]] -= c;
            m[par[node]][node] -= c;
        }
    }
    else{
        int it = 0, kyouko = akari, yui = akari;
        for(; g[pos][it] == par[pos]; it++);
        kyouko = dfsleaf(g[pos][it]);
        it++;
        for(; g[pos][it] == par[pos]; it++);
        yui = dfsleaf(g[pos][it]);
        int c = m[pos][par[pos]];
        ans.pb({{akari, kyouko}, c / 2});
        ans.pb({{akari, yui}, c / 2});
        ans.pb({{kyouko, yui}, -(c / 2)});
        for(int node = pos; node != akari; node = par[node]){
            m[node][par[node]] -= c;
            m[par[node]][node] -= c;
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1, w; i < n; i++){
        cin >> u[i] >> v[i] >> w;
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
        m[u[i]][v[i]] = m[v[i]][u[i]] = w;
    }
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 1){
            akari = i;
        }
        if(g[i].size() == 2){
            cout << "NO\n";
            return;
        }
    }
    dfs1(akari);
    dfs2(akari);
    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i.fi.fi << " " << i.fi.se << " " << i.se << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}