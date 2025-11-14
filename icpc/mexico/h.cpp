
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define debug(x) cout << #x << " => " << x << "\n"
 
const int mod = 1e9 + 7;

void solve() {
	int n, m; cin >> n >> m;

	vector <int> s(n + 5), t(m + 5);
	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		s[i] = c - 'a';
	}

	for(int i = 1; i <= m; i++) {
		char c; cin >> c;
		t[i] = c - 'a';
	}

	vector<vector<vector<int>>> dp(2, vector<vector<int>>(m + 5, vector<int>(2, 0)));

	dp[0][0][0] = 1;

	for(int _i = 1; _i <= n; _i++) {
		int i = _i % 2;
		dp[i].assign(m + 5, vector<int>(2, 0));
		for(int j = 0; j <= m; j++) {
			if(j == 0) {
				(dp[i][j][0] += dp[i ^ 1][j][0]) %= mod;
				(dp[i][j][1] += dp[i ^ 1][j][1]) %= mod;
				(dp[i][j][1] += 25 * dp[i ^ 1][j][0]) %= mod;
				continue;
			}

			if(s[_i] == t[j]) {
				(dp[i][j][0] += dp[i ^ 1][j - 1][0]) %= mod;
				(dp[i][j][1] += dp[i ^ 1][j - 1][1]) %= mod;
			} else {
				(dp[i][j][1] += dp[i ^ 1][j - 1][0]) %= mod;
			}

			(dp[i][j][0] += dp[i ^ 1][j][0]) %= mod;
			(dp[i][j][1] += dp[i ^ 1][j][1]) %= mod;
			(dp[i][j][1] += 25 * dp[i ^ 1][j][0]) %= mod;
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 0; j <= m; j++) {
	// 		cout << dp[i][j][0] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 0; j <= m; j++) {
	// 		cout << dp[i][j][1] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << (dp[n % 2][m][0] + dp[n % 2][m][1]) % mod << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
