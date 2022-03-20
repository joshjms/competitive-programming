// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, m, k, w;
int spp[200005];
vector <pair<int,pair<int,pair<int,int>>>> e;

int par[200005], sz[200005];

int l = -1e18 - 7, r = 1e18 + 7, cv = -1e18 - 7;

int find(int u){
    if(u == par[u])
        return u;
    else return par[u] = find(par[u]);
}

int join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    if(sz[u] >= sz[v]){
        par[v] = u;
        sz[u] += sz[v];
    }
    else{
        par[u] = v;
        sz[v] += sz[u];
    }
    return 1;
}

void resetdsu(){
    for(int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int calc(int x){
    for(int i = 0; i < e.size(); i++)
        e[i].fi += (e[i].se.fi == 0 ? x : 0);
    sort(e.begin(), e.end());
    resetdsu();
    int akarin = 0;
    for(auto i : e){
        if(join(i.se.se.fi, i.se.se.se)){
            akarin += i.se.fi ^ 1;
        }
    }
    for(int i = 0; i < e.size(); i++)
        e[i].fi -= (e[i].se.fi == 0 ? x : 0);
    return akarin;
}

void solve(){
    cin >> n >> m >> k >> w;
    for(int i = 1, u; i <= k; i++){
        cin >> u;
        spp[u] = 1;
    }
    for(int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        e.pb({w * 2, {(spp[u] ^ spp[v] ^ 1), {u, v}}});
    }
    while(l <= r){
        int mid = (l + r) / 2;
        if(calc(mid) >= w)
            l = mid + 1, cv = mid;
        else r = mid - 1;
    }
    for(int i = 0; i < e.size(); i++){
        e[i].fi += (e[i].se.fi == 0 ? cv : 0);
    }
    sort(e.begin(), e.end());
    resetdsu();
    int akarin = 0;
    int chinatsu = 0;
    for(auto i : e){
        if(join(i.se.se.fi, i.se.se.se)){
            akarin += i.fi;
            chinatsu += 1 ^ i.se.fi;
        }
    }
    bool connected = 1;
    for(int i = 2; i <= n; i++){
        if(find(i) != find(1)){
            connected = 0;
            break;
        }
    }
    if(chinatsu >= w && connected)
        cout << (akarin - cv * w) / 2 << "\n";
    else cout << -1 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}