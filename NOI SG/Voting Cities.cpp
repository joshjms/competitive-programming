#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define debug(x) cout << #x << " => " << x << "\n"

#define fi first
#define se second

const int mod = 1e9 + 7;

int n, e, k, q;
vector <pair<int,int>> g[5005];
int sp[5005];

int dp[5005][32];
priority_queue <pair<int,pair<int,int>>> pq;

void solve(){
    cin >> n >> e >> k;
    for(int i = 1, u; i <= k; i++){
        cin >> u;
        sp[u] = 1;
    }
    for(int i = 1, u, v, w; i <= e; i++){
        cin >> u >> v >> w;
        g[v].pb({u, w});
    }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 32; j++)
            dp[i][j] = 1e18 + 7;
    for(int i = 0; i < n; i++)
        if(sp[i] == true){
            pq.push({0, {i, 0}});
            dp[i][0] = 0;
        }
    while(!pq.empty()){
        int pos = pq.top().se.fi;
        int state = pq.top().se.se;
        int cost = -pq.top().fi;
        pq.pop();
        if(cost > dp[pos][state]) continue;
        for(auto i : g[pos]){
            if(cost + i.se < dp[i.fi][state]){
                dp[i.fi][state] = cost + i.se;
                pq.push({-dp[i.fi][state], {i.fi, state}});
            }
            for(int j = 0; j < 5; j++){
                if((state & (1ll << j)) == 0){
                    int extraCost = i.se - (j + 1) * i.se / 10;
                    if(cost + extraCost < dp[i.fi][state | (1ll << j)]){
                        dp[i.fi][state | (1ll << j)] = cost + extraCost;
                        pq.push({-dp[i.fi][state | (1ll << j)], {i.fi, state | (1ll << j)}});
                    }
                }
            }
        }
    }
    cin >> q;
    for(int st, pr[5]; q--;){
        cin >> st;
        for(int i = 0; i < 5; i++)
            cin >> pr[i];
        int akarin = 1e18 + 7;
        for(int i = 0; i < 32; i++){
            int chinatsu = 0;
            bool invalid = false;
            for(int j = 0; j < 5; j++){
                if(i & (1ll << j)){
                    chinatsu += pr[j];
                    if(pr[j] == -1){
                        invalid = true;
                    }
                }
            }
            if(!invalid) akarin = min(akarin, dp[st][i] + chinatsu);
        }
        if(akarin >= 1e15)
            cout << -1 << "\n";
        else cout << akarin << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}