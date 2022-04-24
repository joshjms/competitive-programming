#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int mod = 998244353;

int n, p;
int dp[3005][9005][2];
int ans[3005];

void solve () {
    cin >> n >> p;
    mod = p;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            (dp[i + 1][j + 2][0] += (dp[i][j][1] * 2) % mod) %= mod;
            (dp[i + 1][j + 1][1] += (dp[i][j][1] * 3) % mod) %= mod;
            (dp[i + 1][j][1] += (dp[i][j][1]) % mod) %= mod;
            (dp[i + 1][j + 1][0] += (dp[i][j][0]) % mod) %= mod;
            (dp[i + 1][j][1] += (dp[i][j][0]) % mod) %= mod;
        }
    }
    for(int i = 1; i < n; i++)
        cout << dp[n][i][1] << " ";
    cout << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve ();
}