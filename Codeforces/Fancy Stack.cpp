#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

const int mod = 998244353;

int n, arr[5005], cnt[5005], p[5005];
int dp[5005][2505];
int c[5005][5005];

void solve () {
    cin >> n;
    p[n + 1] = 0;
    for(int i = 1; i <= n; i++) {
        cnt[i] = 0;
        p[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for(int i = n; i >= 1; i--) {
        p[i] = (p[i + 1] + cnt[i]) % mod;
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[n][0] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= n / 2; j++) {
            if(cnt[i] == 0) {
                (dp[i - 1][j] += dp[i][j]) %= mod;
                continue;
            }
            int rooms = max(0ll, j - 1 + (j == n / 2 ? 1 : 0));
            int used = p[i + 1] - j;
            if(rooms - used >= cnt[i] - 1) {
                (dp[i - 1][j + 1] += (dp[i][j] * c[rooms - used][cnt[i] - 1]) % mod) %= mod;
            }
            if(rooms - used >= cnt[i]) {
                (dp[i - 1][j] += (dp[i][j] * c[rooms - used][cnt[i]]) % mod) %= mod;
            }
        }
    }
    cout << dp[0][n / 2] % mod << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i <= 5000; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) {
                c[i][j] = 1;
            }
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    int tc; cin >> tc;
    while(tc--)
        solve ();
}