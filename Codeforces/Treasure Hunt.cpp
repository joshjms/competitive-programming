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

int n, m, s, base_move;
vector <int> g[305];
vector <int> degree[305];
int flag[305];

int moves;
string res = "WA";

int adj;
vector <pair<int,int>> adjs;

int peko[305];
int cur, prv;

void solve(){
    cin >> n >> m >> s >> base_move; 
    memset(peko, 0, sizeof(peko));
    for(int i = 1; i <= n; i++){
        g[i].clear();
        flag[i] = 0;
    }
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        for(auto j : g[i]){
            peko[g[j].size()]++;
        }
    }
    prv = 1;
    while(true){
        ++cur;
        cin >> res;
        if(res == "AC") break;
        cin >> adj;
        peko[adj] -= prv;
        adjs.clear();
        for(int i = 1, a, b; i <= adj; i++){
            cin >> a >> b;
            adjs.pb({a, b ^ 1});
        }
        pair<int,int> choose = {-1e9, -1e9};
        for(int i = 0; i < adjs.size(); i++){
            choose = max(choose, {peko[adjs[i].fi], i + 1});
        }
        cout << choose.se << endl;
        prv = choose.fi;
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