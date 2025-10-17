
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 998244353;

void solve() {
	string s;
	cin >> s;

	int n = s.size();

	int dp[n + 5][n + 5];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n; j++) {
			// debt
			(dp[i + 1][j + 1] += dp[i][j]) %= mod;

			// connect this with something behind
			(dp[i + 1][j] += (dp[i][j] * (j)) % mod) %= mod;

			// pay off debt
			if(s[i] == '1' && j > 0) {
				(dp[i + 1][j - 1] += (((dp[i][j] * j) % mod) * (j)) % mod) %= mod;
			}

			// pay off debt but make new one
			if(s[i] == '1') {
				(dp[i + 1][j] += (dp[i][j] * j) % mod) %= mod;
			}
		}
	}

	// for(int i = 0; i < n + 1; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[n][0] << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
