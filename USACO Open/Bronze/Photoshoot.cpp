#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n";

int n, dp[200005][2];
string s;

void solve() {
    cin >> n >> s;
    if(s[0] == 'G' && s[1] == 'H') dp[0][0]++;
    if(s[0] == 'H' && s[1] == 'G') dp[0][1]++;
    for(int i = 2; i < n; i += 2) {
        if(s[i] == 'G' && s[i + 1] == 'H'){
            dp[i][0] = min(dp[i - 2][1] + 1, dp[i - 2][0] + 2);
            dp[i][1] = min(dp[i - 2][1], dp[i - 2][0] + 1);
        }
        else if(s[i] == 'H' && s[i + 1] == 'G') {
            dp[i][0] = min(dp[i - 2][0], dp[i - 2][1] + 1);
            dp[i][1] = min(dp[i - 2][0] + 1, dp[i - 2][1] + 2);
        }
        else{
            dp[i][0] = dp[i - 2][0];
            dp[i][1] = dp[i - 2][1];
        }
    }
    cout << dp[n - 2][0] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}