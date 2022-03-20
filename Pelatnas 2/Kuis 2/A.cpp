#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define debug(x)    cout << #x << " => " << x << "\n"
#define pb          push_back
#define fi          first
#define se          second
#define sp          " "

int n, m, a[245][245], c[245][245];
int min_len = 1e18 + 7, min_median = 1e18 + 7;
int l, r;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair <int,int> ans = {1e18 + 7, 1e18 + 7};

bool valid(int x, int y){
    if(x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] != 0)
        return true;
    return false;
}

// bool bfs(int batas){
//     bool vis[n + 1][m + 1][256][n * m + 1];
//     memset(vis, 0, sizeof(vis));
//     queue <pair<pair<int,int>,pair<int,int>>> bfs; 
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(c[i][j] == 0) continue;
//             bfs.push({{i, j}, {(1ll << c[i][j]), 1}});
//             vis[i][j][(1ll << c[i][j])][1] = 1;
//         }
//     }
//     while(!bfs.empty()){
//         int x = bfs.front().fi.fi;
//         int y = bfs.front().fi.se;
//         int state = bfs.front().se.fi;
//         int steps = bfs.front().se.se;
//         bfs.pop();
//         if(__builtin_popcount(state) >= 5) return true;
//         if(steps == batas) continue;
//         for(int i = 0; i < 4; i++) if(valid(x + dx[i], y + dy[i])){
//             int newState = state | (1ll << c[x + dx[i]][y + dy[i]]);
//             if(!vis[x + dx[i]][y + dy[i]][newState][steps + 1]){
//                 vis[x + dx[i]][y + dy[i]][newState][steps + 1] = 1;
//                 bfs.push({{x + dx[i], y + dy[i]}, {newState, steps + 1}});
//             }
//         } 
//     }
//     return false;
// }

// bool median(int batas){
//     bool vis[n + 1][m + 1][256][n * m + 1][n * m + 1];
//     memset(vis, 0, sizeof(vis));
//     queue <pair<pair<int,int>,pair<int,int>>> bfs; 
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             if(c[i][j] == 0) continue;
//             bfs.push({{i, j}, {(1ll << c[i][j]), 1}});
//             vis[i][j][(1ll << c[i][j])][1] = 1;
//         }
//     }
//     while(!bfs.empty()){
//         int x = bfs.front().fi.fi;
//         int y = bfs.front().fi.se;
//         int state = bfs.front().se.fi;
//         int steps = bfs.front().se.se;
//         bfs.pop();
//         if(__builtin_popcount(state) >= 5) return true;
//         if(steps == batas) continue;
//         for(int i = 0; i < 4; i++) if(valid(x + dx[i], y + dy[i])){
//             int newState = state | (1ll << c[x + dx[i]][y + dy[i]]);
//             if(!vis[x + dx[i]][y + dy[i]][newState][steps + 1]){
//                 vis[x + dx[i]][y + dy[i]][newState][steps + 1] = 1;
//                 bfs.push({{x + dx[i], y + dy[i]}, {newState, steps + 1}});
//             }
//         } 
//     }
//     return false;
// }

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < (1ll << n * m); i++){
        int mask = i;
        if(__builtin_popcount(mask) < 5) continue;
        bool have[n+1][m+1];
        bool vis[n+1][m+1];
        memset(have, 0, sizeof(have));
        memset(vis, 0, sizeof(vis));
        queue <pair<int,int>> q;
        bool ok = true;
        int u, v;
        for(int j = 0; j < n * m; j++){
            if(mask & (1ll << j)){
                int row = j / m;
                int col = j % m;
                have[row][col] = 1;
                u = row, v = col;
                if(c[row][col] == 0){
                    ok = false;
                    break;
                }
            }
        }
        if(ok == false) continue;
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        vis[u][v] = 1;
        q.push({u, v});
        vector <int> peko;
        while(!q.empty()){
            int x = q.front().fi;
            int y = q.front().se;
            peko.push_back(a[x][y]);
            cnt[c[x][y]] = 1;
            q.pop();
            for(int j = 0; j < 4; j++) if(valid(x + dx[j], y + dy[j])){
                if(have[x + dx[j]][y + dy[j]] && !vis[x + dx[j]][y + dy[j]]){
                    vis[x + dx[j]][y + dy[j]] = 1;
                    q.push({x + dx[j], y + dy[j]});
                }
            }
        }
        ok = true;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(have[j][k] && !vis[j][k]){
                    ok = false;
                    break;
                }
            }
            if(ok == false)
                break;
        }
        int dis = 0;
        for(int j = 0; j <= 8; j++)
            dis += cnt[j];
        if(ok == false || dis < 5)
            continue;
        sort(peko.begin(), peko.end());
        if(peko[peko.size() / 2] == 1 && __builtin_popcount(mask) == 5){
            for(int j = 0; j < n * m; j++){
                if(mask & (1ll << j)){
                    cout << j / m << " " << j % m << "\n";
                }
            }
        }
        ans = min(ans, {__builtin_popcount(mask), peko[peko.size() / 2]});
    }
    cout << ans.fi << " " << ans.se << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}