#include <bits/stdc++.h>
using namespace std;
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, k;
vector <int> g[50005];
int dp[50005][505];
int ans;

void dfs(int pos, int par){
    dp[pos][0]++;
    for(auto i : g[pos]) if(i != par){
        dfs(i, pos);
        for(int j = 0; j <= k; j++){
            ans += dp[pos][j] * dp[i][k - j - 1];
        }
        for(int j = 1; j <= k; j++){
            dp[pos][j] += dp[i][j - 1];
        }
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // rooted at 1
    dfs(1, -1);
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}

#include "experiment.h"

#include <vector>

std::vector<long long> get_experiment_results(int N, int M,
                                              std::vector<int> P, std::vector<int> Q,
                                              std::vector<int> L, std::vector<int> R,
                                              std::vector<int> D, std::vector<int> U) {
    std::vector<long long> ans(M, -1);
    return ans;
}
