#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, x, y;
int g[105][105];
int dp[105][105];
queue <pair<int,int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool vis[105][105];

void solve () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dp[i][j] = 1e9;
        }
    }
    cin >> x >> y;
    q.push({x, y});
    dp[x][y] = 1;
    vis[x][y] = true;
    while(q.empty() == false) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        if(u == 1 || u == n || v == 1 || v == m) {
            cout << dp[u][v] << "\n";
            return;
        }
        for(int i = 0; i < 4; i++) {
            if(g[u + dx[i]][v + dy[i]] == 0 && vis[u + dx[i]][v + dy[i]] == false) {
                vis[u + dx[i]][v + dy[i]] = true;
                dp[u + dx[i]][v + dy[i]] = dp[u][v] + 1;
                q.push({u + dx[i], v + dy[i]});
            }
        }
    }
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}