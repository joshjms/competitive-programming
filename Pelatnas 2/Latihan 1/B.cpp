// アッカリ〜ン

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int tc;

int x, y, ans;
int dp[35][2][2];

int modex(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void solve(){
    cin >> tc;
    while(tc--){
        cin >> x >> y;
        int akarin = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = dp[0][1][1] = 1;
        for(int i = 0; i < 30; i++){
            int u = (x >> i) & 1;
            int v = (y >> i) & 1;
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    int _u = u ? 0 : j;
                    int _v = v ? 0 : k;
                    if(j == 0 || j == 1 && (x & (1ll << i)))
                        (dp[i + 1][j][k] += dp[i][j][_v]) %= mod;
                    if(k == 0 || k == 1 && (y & (1ll << i)))
                        (dp[i + 1][j][k] += dp[i][_u][k]) %= mod;
                    (dp[i + 1][j][k] += dp[i][_u][_v]) %= mod;
                }
            }
        }
        ans = 0;
        for(int i = 0; i < 30; i++){
            if(x >= (1ll << i))
                (ans += ((i + 1) * dp[i][x < (2ll << i)][y < (1ll << i)]) % mod) %= mod;
            if(y >= (1ll << i))
                (ans += ((i + 1) * dp[i][x < (1ll << i)][y < (2ll << i)]) % mod) %= mod;
        }
        cout << ans << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}