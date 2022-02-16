#include <bits/stdc++.h>
using namespace std;

// Template by YuriEnthusiast 2022 <3

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 998244353;
const ld err = 1e-6;

int n, m, ans;
int arr[1005][2];
string x, y;

int f(int l1, int r1, int l2, int r2){
    // cout << l1 << "-" << r1 << ", " << l2 << "-" << r2;
    int dp[n + 5][m + 5][2];
    memset(dp, 0, sizeof(dp));

    dp[l1][l2][0] = 1;

    for(int i = l1; i <= r1 + 1; i++){
        for(int j = l2; j <= r2 + 1; j++){
            if((i == l1 || arr[i][0] != arr[i - 1][0]) && i <= r1)
                (dp[i + 1][j][0] += dp[i][j][0]) %= mod;
            if((j == l2 || arr[i][0] != arr[j - 1][1]) && i <= r1)
                (dp[i + 1][j][0] += dp[i][j][1]) %= mod;
            if((i == l1 || arr[j][1] != arr[i - 1][0]) && j <= r2)
                (dp[i][j + 1][1] += dp[i][j][0]) %= mod;
            if((j == l2 || arr[j][1] != arr[j - 1][1]) && j <= r2)
                (dp[i][j + 1][1] += dp[i][j][1]) %= mod;
        }
    }

    // for(int i = l1; i <= r1 + 1; i++){
    //     for(int j = l2; j <= r2 + 1; j++){
    //         cout << i << ", " << j << " => ";
    //         cout << dp[i][j][0] << " " << dp[i][j][1] << "\n";
    //     }
    //     cout << "\n";
    // }

    return (dp[r1 + 1][r2 + 1][0] + dp[r1 + 1][r2 + 1][1]) % mod;
}

void solve(){
    cin >> x >> y;
    n = x.size();
    m = y.size();
    for(int i = 0; i < n; i++)
        arr[i + 1][0] = x[i] - 'a';
    for(int i = 0; i < m; i++)
        arr[i + 1][1] = y[i] - 'a';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
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