#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 1e9 + 7;

int n, m, b[30005], p[30005];
vector <pair<pair<int,int>,int>> g[30005][180];
int dp[30005][180];
bool doge[30005][180];

priority_queue <pair<int,pair<int,int>>> pq;
map <pair<int,int>,bool> mp;

void solve () {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> b[i] >> p[i];
        if(mp[{b[i], p[i]}]) continue;
        mp[{b[i], p[i]}] = true;
        if(p[i] <= 45)
            doge[b[i]][p[i]] = true;
        if(p[i] > 45) {
            for(int j = b[i] - p[i], c = 1; j >= 0; j -= p[i], c++)
                g[b[i]][0].pb({{j, 0}, c});
            for(int j = b[i] + p[i], c = 1; j < n; j += p[i], c++)
                g[b[i]][0].pb({{j, 0}, c});
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 45; j++) {
            dp[i][j] = 1e9 + 7;
        }
    }
    dp[b[0]][0] = 0;
    pq.push({0, {b[0], 0}});
    while(!pq.empty()) {
        int cost = -pq.top().fi;
        int pos = pq.top().se.fi;
        int pow = pq.top().se.se;
        pq.pop();
        if(cost > dp[pos][pow]) continue;
        if(pos == b[1]) {
            cout << cost << "\n";
            return;
        }
        if(pow == 0) {
            for(auto c : g[pos][pow]) {
                if(dp[c.fi.fi][c.fi.se] > cost + c.se) {
                    dp[c.fi.fi][c.fi.se] = cost + c.se;
                    pq.push({-dp[c.fi.fi][c.fi.se], {c.fi.fi, c.fi.se}});
                }
            }
        }
        else {
            if(pos + pow < n) {
                if(dp[pos + pow][pow] > cost + 1) {
                    dp[pos + pow][pow] = cost + 1;
                    pq.push({-dp[pos + pow][pow], {pos + pow, pow}});
                }
            }
            if(pos - pow >= 0) {
                if(dp[pos - pow][pow] > cost + 1) {
                    dp[pos - pow][pow] = cost + 1;
                    pq.push({-dp[pos - pow][pow], {pos - pow, pow}});
                }
            }
        }
        for(int i = 0; i <= 45; i++) {
            if(i == pow) continue;
            if(i == 0 || doge[pos][i] == true) {
                if(dp[pos][i] > cost) {
                    dp[pos][i] = cost;
                    pq.push({-dp[pos][i], {pos, i}});
                }
            }
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j * j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << -1 << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}