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

int n, k, ans;
int arr[505][505], g[505][505][4];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int inv[4] = {2, 3, 0, 1};

int md[505][505];
priority_queue <pair<int,pair<int,int>>> pq;

bool acceptable(int u, int v){
    if(u >= 1 && u <= k + 1 && v >= 1 && v <= k + 1)
        return true;
    return false;
}

void solve(){
    cin >> n >> k;
    ans = 0;
    for(int i = 0; i <= k + 1; i++){
        for(int j = 0; j <= k + 1; j++){
            for(int l = 0; l < 4; l++)
                g[i][j][l] = 0;
        }
    }
    for(int i = 1, ra, ca, rb, cb; i <= n; i++){
        cin >> ra >> ca >> rb >> cb;
        if(ra == rb){
            g[ra][max(ca, cb)][1]--;
            g[ra+1][max(ca, cb)][3]--;
        }
        else{
            g[max(ra, rb)][ca][0]--;
            g[max(ra, rb)][ca+1][2]--;
        }
    }
    for(int i = 1; i <= k + 1; i++){
        for(int j = 1; j <= k + 1; j++){
            md[i][j] = -1e9 + 7;
        }
    }
    md[(k+1)/2][(k+1)/2] = 0;
    pq.push({0, {(k + 2) / 2, (k + 2) / 2}});
    for(int w, x, y, mx, my, nw; !pq.empty();){
        w = pq.top().fi;
        x = pq.top().se.fi;
        y = pq.top().se.se;
        mx = k + 2 - x;
        my = k + 2 - y;
        pq.pop();
        if(md[x][y] > w) continue;
        if(x == 1 || y == 1 || x == k + 1 || y == k + 1){
            ans = max(ans, n + w);
        }
        for(int i = 0; i < 4; i++){
            if(acceptable(x + dx[i], y + dy[i])){
                nw = w + g[x][y][i] + g[mx][my][inv[i]];
                if(md[x + dx[i]][y + dy[i]] <  nw){
                    md[x + dx[i]][y + dy[i]] = nw;
                    pq.push({nw, {x + dx[i], y + dy[i]}});
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}