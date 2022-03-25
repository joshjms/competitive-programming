#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n;
vector <int> g[100005];
vector <int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int pos){
    int size = 1;
    int max_c_size = 0;
    for(auto c : g[pos]) if(c != parent[pos]) {
        parent[c] = pos;
        depth[c] = depth[pos] + 1;
        int c_size = dfs(c);
        size += c_size;
        if(c_size > max_c_size)
            max_c_size = c_size, heavy[pos] = c;
    }
    return size;
}

void decompose(int v, int h){
    head[v] = h, pos[v] = cur_pos++;
    if(heavy[v] != -1)
        decompose(heavy[v], h);
    for(auto c : g[v]){
        if(c != parent[v] && c != heavy[v]){
            decompose(c, c);
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    parent = vector <int> (n);
    depth = vector <int> (n);
    heavy = vector <int> (n - 1);
    head = vector <int> (n);
    pos = vector <int> (n);
    cur_pos = 0;
    dfs(0);
    decompose(0, 0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}