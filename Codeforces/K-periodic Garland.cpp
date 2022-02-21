// AKARINNN!!!!!!!!! <3

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

int n, k, ps[1000005], akari;
char c[1000005];
int dp[1000005];

int sum(int l, int r){
    return ps[r] - ps[l - 1];
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        ps[i] = ps[i - 1] + c[i] - '0';
        dp[i] = 0;
    }
    // dp[i] = minimum cost using c[i] (ending at c[i])
    for(int i = 1; i <= n; i++){
        if(i <= k)
            dp[i] = sum(1, i - 1) + (c[i] == '1' ? 0 : 1);
        else dp[i] = min(dp[i - k] + sum(i - k + 1, i - 1), sum(1, i - 1)) + (c[i] == '1' ? 0 : 1);
    }
    akari = 1e18 + 7;
    for(int i = 0; i <= n; i++){
        akari = min(akari, dp[i] + sum(i + 1, n));
    }
    cout << akari << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--)
        solve();
}