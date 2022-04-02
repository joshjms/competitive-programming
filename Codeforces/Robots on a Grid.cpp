#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, m, ans1, ans2;
vector <string> c, s; 
vector <int> rpath [1000005];
int path[1000005], cycle[1000005];
bool vis[1000005], viscyc[1000005];
int kwok[1000005], head[1000005], sz[1000005];
set <int> st[1000005];

void reset() {
    for(int i = 0; i < n * m; i++) {
        path[i] = -1;
        cycle[i] = 0;
        vis[i] = 0;
        viscyc[i] = 0;
        kwok[i] = -1;
        head[i] = -1;
        sz[i] = -1;
        st[i].clear();
        rpath[i].clear();
    }
}

void makeEdge(int u, int v) {
    path[u] = v;
    rpath[v].pb(u);
}

void dfs(int pos) {
    if(viscyc[pos]) { cycle[pos] = 1; return; }
    viscyc[pos] = 1;
    if(vis[path[pos]] == 0)
        dfs(path[pos]);
    viscyc[pos] = 0;
    vis[pos] = 1;
}

void dfs2(int pos, int h, int val) {
    if(pos == -1) return;
    kwok[pos] = val;
    head[pos] = h;
    assert(sz[h] != 0);
    for(auto c : rpath[pos]) {
        dfs2(c, h, (val - 1 + sz[h]) % sz[h]);
    }
}

void solve (){
    cin >> n >> m;
    c.resize(n);
    s.resize(n);
    ans1 = ans2 = 0;
    reset();
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'U') makeEdge(i * m + j, (i - 1) * m + j);
            if(s[i][j] == 'D') makeEdge(i * m + j, (i + 1) * m + j);
            if(s[i][j] == 'L') makeEdge(i * m + j, i * m + (j - 1));
            if(s[i][j] == 'R') makeEdge(i * m + j, i * m + (j + 1));
        }
    }
    for(int i = 0; i < n * m; i++) {
        if(vis[i] == false)
            dfs(i);
    }
    for(int i = 0; i < n * m; i++) {
        if(cycle[i] == true) {
            int tmr = 0, pos = i;
            do {
                kwok[pos] = tmr++;
                head[pos] = i;
                pos = path[pos];
            } while(cycle[pos] == 0);
            sz[i] = tmr;
            ans1 += sz[i];
        }
    }
    for(int i = 0; i < n * m; i++) {
        if(head[i] == -1 && head[path[i]] != -1) {
            dfs2(i, head[path[i]], (kwok[path[i]] - 1 + sz[head[path[i]]]) % sz[head[path[i]]]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == '0') {
                assert(head[i * m + j] != -1);
                st[head[i * m + j]].insert(kwok[i * m + j]);
            }
        }
    }
    for(int i = 0; i < n * m; i++) {
        ans2 += st[i].size();
    }
    cout << ans1 << " " << ans2 << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve ();
}