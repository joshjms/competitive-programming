#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k, a[1005][1005], ans[1005][1005];

int par[1000005], sum[1000005];

int find(int u) {
    return (u == par[u]) ? u : par[u] = find(par[u]);
}

int join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return 0;
    par[u] = v;
    sum[v] += sum[u];
    return 1;
}

vector <pair<int,pair<int,int>>> v;

int idx(int i, int j) {
    return i * m + j;
}

int c;
bool vis[1005][1005];

bool valid(int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void dfs(int x, int y, int v) {
    if(c == k / v) return;
    vis[x][y] = 1, ans[x][y] = v, c++;
    for(int i = 0; i < 4; i++) {
        if(valid(x + dx[i], y + dy[i]) && vis[x + dx[i]][y + dy[i]] == false && a[x + dx[i]][y + dy[i]] >= v) {
            dfs(x + dx[i], y + dy[i], v);
        }
    }
}

void solve () {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            v.push_back({a[i][j], {i, j}});
            par[idx(i, j)] = -1;
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        int h = v[i].fi;
        int x = v[i].se.fi, y = v[i].se.se;
        par[idx(x, y)] = idx(x, y);
        sum[idx(x, y)] = 1;
        for(int j = 0; j < 4; j++) {
            if(valid(x + dx[j], y + dy[j]) && par[idx(x + dx[j], y + dy[j])] != -1)
                join(idx(x, y), idx(x + dx[j], y + dy[j]));
        }
        if(k % h == 0 && k / h <= sum[find(idx(x, y))]) {
            cout << "YES\n";
            dfs(x, y, h);
            for(int ii = 0; ii < n; ii++) {
                for(int jj = 0; jj < m; jj++){
                    cout << ans[ii][jj] << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}