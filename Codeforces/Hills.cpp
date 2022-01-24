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

int n, arr[5005], dp[5005][5005][2];
// dp i = up to idx i, j = houses, k = take

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i <= n + 2; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = 1e9 + 7;
            }
        }
    }
    dp[1][0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            // take
            dp[i + 2][j + 1][1] = min(dp[i + 2][j + 1][1], dp[i][j][0] + max(0ll, arr[i - 1] - arr[i] + 1) + max(0ll, arr[i + 1] - arr[i] + 1));
            dp[i + 2][j + 1][1] = min(dp[i + 2][j + 1][1], dp[i][j][1] + max(0ll, min(arr[i - 1], arr[i - 2] - 1) - arr[i] + 1) + max(0ll, arr[i + 1] - arr[i] + 1));
            // not take
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0]);
            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][1]);
        }
    }
    // for(int k = 0; k < 2; k++){
    //     for(int i = 1; i <= n + 2; i++){
    //         for(int j = 0; j <= n; j++){
    //             if(dp[i][j][k] >= 1e9 + 7) cout << "x ";
    //             else cout << dp[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }
    for(int i = 1; i <= (n + 1) / 2; i++){
        cout << min(dp[n + 1][i][0], min(dp[n + 1][i][1], min(dp[n + 2][i][0], dp[n + 2][i][1]))) << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}