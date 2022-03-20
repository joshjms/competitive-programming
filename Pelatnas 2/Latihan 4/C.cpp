// アッカリ〜ン

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define ll          long long
#define ld          long double

#define debug(x)    cout << #x << " => " << x << "\n";
#define sp          " "
#define pb          push_back
#define fi          first
#define se          second

const int mod = 1e9 + 7;

int n, m, ans;
int arr[1005], cost[1205];
int dp[10005][1205];
char g[1205][15];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n * m; i++){
        for(int j = 0; j < (1ll << m); j++){
            dp[i][j] = 1e18 + 7;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n * m; i++){
        int row = (i - 1) / m + 1;
        int col = (i - 1) % m;
        for(int j = 0; j < (1ll << m); j++){
            if(g[row][col] == '.'){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j ^ (1ll << col)]);
                continue;
            }
            if((1 << col) & j){
                // vertical
                int k = j ^ (1ll << col);
                if(g[row - 1][col] == '#')
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + 1);
                else dp[i][j] = dp[i - 1][j] + 1;
            }
            else{
                // horizontal
                if(col == 0 || (1 << (col - 1)) & j || g[row][col - 1] == '.'){
                    int k = j ^ (1ll << col); // from vertical
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i - 1][k] + 1);
                }
                else{
                    int k = j ^ (1ll << col);
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][k]);
                }
            }
        }
    }
    // for(int i = 1; i <= n * m; i++){
    //     for(int j = 0; j < (1ll << m); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    ans = 1e18 + 7;
    for(int i = 0; i < (1ll << m); i++)
        ans = min(ans, dp[n * m][i]);
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}