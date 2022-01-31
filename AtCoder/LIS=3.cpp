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

int n, m;
int dp[1005][13][13][13];
int ans;

void solve(){
    cin >> n >> m;
    dp[1][0][0][0] = 1;
    for(int idx = 1; idx <= n; idx++){
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= m; k++){
                    if(dp[idx][i][j][k] == 0) continue;
                    for(int nd = 1; nd <= m; nd++){
                        if(i == 0){
                            (dp[idx + 1][nd][0][0] += dp[idx][i][j][k]) %= mod;
                        }
                        else if(j == 0){
                            if(nd > i){
                                (dp[idx + 1][i][nd][0] += dp[idx][i][j][k]) %= mod;
                            }
                            else (dp[idx + 1][min(i, nd)][0][0] += dp[idx][i][j][k]) %= mod;
                        }
                        else if(k == 0){
                            if(nd > j){
                                (dp[idx + 1][i][min(j, nd)][nd] += dp[idx][i][j][k]) %= mod;
                            }
                            else if(nd > i){
                                (dp[idx + 1][i][min(j, nd)][0] += dp[idx][i][j][k]) %= mod;
                            }
                            else (dp[idx + 1][min(i, nd)][j][0] += dp[idx][i][j][k]) %= mod;
                        }
                        else{
                            if(nd <= k){
                                if(nd > j){
                                    (dp[idx + 1][i][min(j, nd)][nd] += dp[idx][i][j][k]) %= mod;
                                }
                                else if(nd > i){
                                    (dp[idx + 1][i][min(j, nd)][k] += dp[idx][i][j][k]) %= mod;
                                }
                                else (dp[idx + 1][min(i, nd)][j][k] += dp[idx][i][j][k]) %= mod;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 2; j <= m; j++){
            for(int k = 3; k <= m; k++){
                if(dp[n + 1][i][j][k] == 0) continue;
                (ans += dp[n + 1][i][j][k]) %= mod;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}