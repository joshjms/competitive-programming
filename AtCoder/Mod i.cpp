#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define sp " "
#define debug(x) cout << #x << " => " << x << "\n"

const int mod = 1e9 + 7;
const ld err = 1e-6;

int n, arr[3005], pref[3005][3005], dp[3005][3005], cnt[3005], sum[3005], ans;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref[i][j] = (pref[i][j - 1] + arr[j]) % i;
        }
    }
    for(int i = 1; i <= n; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            cnt[j] = 0;
            sum[j] = 0;
        }
        for(int j = i; j <= n; j++){ 
            cnt[pref[i][j - 1]]++;
            (sum[pref[i][j - 1]] += dp[i - 1][j - 1]) %= mod;
            (dp[i][j] += sum[pref[i][j]]) %= mod;
        }
    }
    for(int i = 1; i <= n; i++){
        (ans += dp[i][n]) %= mod;
    }
    cout << ans << "\n";
}

signed main(){
    solve();
}